#include "GUIOfWar.h"

GUIOfWar::GUIOfWar(string setupFile)
{

    int resp;
    cout << "Choose your mode:" << endl
         << "1. Real \n2. Design" << endl;
    cin >> resp;

    // clear buffer
    cin.ignore(30, '\n');

    if (resp == 1)
    {
        this->real = true;
    }
    else
    {
        this->real = false;
    }

    if (this->real)
    {
        this->player = new CPU();
    }
    else
    {
        this->player = new GUIUser();
    }

    cout << "Initialising map" << endl;

    ifstream inputFile(setupFile);
    vector<string> lines;
    string line;

    while (getline(inputFile, line) && line.at(0) != '#')
    {
        lines.push_back(line);
    }

    inputFile.close();

    string name = "";
    int colour = 0;
    string temp = "";
    for (int i = 0; i < lines.at(0).length(); i++)
    {
        if (lines.at(0).at(i) == ':')
        {
            name = temp;
            temp = "";
        }
        else
        {
            temp += (lines.at(0).at(i));
            if (i == lines.at(0).length() - 1)
            {
                colour = stoi(temp);
                temp = "";
            }
        }
    }
    groupOne = new Alliances(name, colour);
    name = "";
    colour = 0;

    for (int i = 0; i < lines.at(1).length(); i++)
    {
        if (lines.at(1).at(i) == ':')
        {
            name = temp;
            temp = "";
        }
        else
        {
            temp += (lines.at(1).at(i));
            if (i == lines.at(1).length() - 1)
            {
                colour = stoi(temp);
                temp = "";
            }
        }
    }
    groupTwo = new Alliances(name, colour);

    map = new Map(setupFile, player);

    this->turn = true;
}

void GUIOfWar::takeTurn(int actions, sf::RenderWindow *window, vector<sf::Drawable *> &ui)
{
    sf::Event event;
    while (window->pollEvent(event))
    {
    }
    window->clear(sf::Color::Black);
    map->draw(window, NULL);
    for (int i = 0; i < ui.size(); i++)
    {
        window->draw(*(ui.at(i)));
    }
    window->display();
    Alliances *active = (turn) ? this->groupOne : this->groupTwo;
    while (actions > 0)
    {
        // window->clear(sf::Color::Black);
        // map->setAreaBorders();
        // map->draw(window, &c);
        // window->display();
        /*
        Inspect
        */
        // this->player->inspect(this->map);
        //   window->clear(sf::Color::Black);
        //  //map->setAreaBorders();
        //  map->draw(window, &c);
        //  window->display();

        /*
        Choose a country
        */
        vector<Country *> countries = this->map->getCountriesByColour(active->getColour());
        int countryIndex = 0;
        if (countries.size() == 0)
        {
            cout << "This alliance has no countries left" << endl;
            cout << "END OF WAR" << endl;
            return;
        }
        else
        {
            countryIndex = this->player->chooseCountry(countries, this->map, window, ui);
        }

        /*
        Get areas occupied by this country
        */
        vector<Area *> areas = this->map->getAreasByCountry(countries.at(countryIndex));

        /*
        Choose area to take action in
        */
        int areaIndex = -1;
        if (areas.size() == 0)
        {
            cout << "This country occupies no areas - look for areas in your alliance" << endl;
            if (countries.at(countryIndex)->getAlliances() != NULL)
                areas = this->map->getAreasByColour(countries.at(countryIndex)->getAlliances()->getColour());
            if (areas.size() == 0)
            {
                cout << "Looks like there's nowhere to go... END TURN" << endl;
                break;
            }
        }
        else
        {

            while (areaIndex == -1)
            {
                Area *selected = this->player->chooseAreaForAction(areas, window, map, ui);
                for (int i = 0; i < areas.size(); i++)
                {
                    if (areas.at(i) == selected)
                    {
                        areaIndex = i;
                    }
                }
                if (areaIndex == -1)
                {
                    cout << "Select a valid area" << endl;
                }
            }
        }
        cout << "escaped" << endl;
        if (areaIndex == -1)
        {
            break;
        }

        /*
        Select an action
        */
        cout << "going in " << areaIndex << endl;
        int action = this->player->chooseActionForCountry(areas.at(areaIndex), this->map, window, ui);
        cout << "action is " << action << endl;
        /*
        Chosen to attack transport route
        */
        if (action == 1)
        {
            /*
            List of adjacent areas to destroy transport routes between
            */
            vector<Area *> adjacentAreas = this->map->listAdjacent(areas.at(areaIndex), false);
            vector<vector<Area *>> adjacentOfAdjAreas;
            int *index = NULL;
            if (adjacentAreas.size() == 0)
            {
                cout << "No adjacent areas" << endl;
                break;
            }
            // else if (adjacentAreas.size() == 1)
            // {
            //     adjAreaIndex = 0;
            // }
            else
            {
                for (auto it : adjacentAreas)
                {
                    adjacentOfAdjAreas.push_back(this->map->listAdjacent(it, true));
                }
                index = player->chooseAreasToDestroyTransportRoutes(adjacentAreas, adjacentOfAdjAreas, areas.at(areaIndex), window, ui, map);
            }

            if (index != NULL)
            {

                cout << areas.at(areaIndex)->getIndex() << "(" << areas.at(areaIndex)->getColour() << ")"
                     << "Destroying route between:" << endl
                     << adjacentAreas.at(index[0])->toString() << endl
                     << adjacentOfAdjAreas.at(index[0]).at(index[1])->toString() << endl;

                this->map->destroyTransportRoute(adjacentAreas.at(index[0]), adjacentOfAdjAreas.at(index[0]).at(index[1]));
                delete[] index;
                index = NULL;
            }
            else
            {
                cout << "No transport routes to destroy" << endl;
            }
        }
        /*
        Request resources
        */
        else if (action == 2)
        {
            int resource = this->player->chooseResource(areas.at(areaIndex));
            if (resource == -1)
            {
                cout << "This area already has all factories" << endl;
            }
            else if (areas.at(areaIndex)->requestFactory(resource))
            {
                cout << "Factory succesfully acquired" << endl;
                cout << areas.at(areaIndex)->toString();
            }
            else
            {
                cout << "Area could not acquire requested factory" << endl;
            }
        }
        /*
        March to adjacent area
        */
        else if (action == 0)
        {
            /*
            List of adjacent areas to march to
            */
            vector<Area *> adjacentAreas = this->map->listAdjacent(areas.at(areaIndex), false);
            int adjAreaIndex = -1;
            if (adjacentAreas.size() == 0)
            {
                cout << "No adjacent areas" << endl;
                break;
            }
            else if (adjacentAreas.size() == 1)
            {
                adjAreaIndex = 0;
            }
            else
            {
                cout << "Here 4" << endl;
                while (adjAreaIndex == -1)
                {
                    cout << "Here 5" << endl;
                    Area *selected = this->player->chooseAdjacentArea(adjacentAreas, areas.at(areaIndex), window, ui, map);
                    cout << "Here 6 size: " << adjacentAreas.size() << endl;
                    for (int i = 0; i < adjacentAreas.size(); i++)
                    {
                        cout << "Started" << i << endl;
                        if (adjacentAreas.at(i) == selected)
                        {
                            adjAreaIndex = i;
                        }
                        cout << "Completed" << i << endl;
                    }
                    if (adjAreaIndex == -1)
                    {
                        cout << "Select a valid area" << endl;
                    }
                }
            }
            dynamic_cast<sf::Text *>(ui.at(4))->setString("Marching from " + areas.at(areaIndex)->getName() + " to " + adjacentAreas.at(adjAreaIndex)->getName());
            cout << "Marching from " << areas.at(areaIndex)->getName() << " to " << adjacentAreas.at(adjAreaIndex)->getName() << endl;
            areas.at(areaIndex)->marchOut(adjacentAreas.at(adjAreaIndex));
        }
        else if (action == 3)
        {
            countries.at(countryIndex)->recruitPlatoon(this->map, window, ui);
        }
        else if (action == 5)
        {
            Area *selected = NULL;
            while (selected == NULL)
            {
                selected = player->chooseAreaForAction(areas, window, map, ui);
            }
            dynamic_cast<sf::Text *>(ui.at(4))->setString(selected->toString());
            window->clear(sf::Color::Black);
            map->draw(window, NULL);
            for (int i = 0; i < ui.size(); i++)
            {
                window->draw(*(ui.at(i)));
            }
            window->display();
            actions = actions + 1;
        }
        else
        {
            actions = 0;
        }
        actions--;
        cout << "actions remaining " << actions << endl;
        window->clear(sf::Color::Black);
        map->draw(window, NULL);
        for (int i = 0; i < ui.size(); i++)
        {
            window->draw(*(ui.at(i)));
        }
        window->display();
    }
    // window->clear(sf::Color::Black);
    //     //map->setAreaBorders();
    //     map->draw(window, &c);
    //     window->display();
}

void GUIOfWar::warLoop()
{
    const int WINDOW_X = 1280;
    const int WINDOW_Y = 640;
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "My window");

    map->setAreaBorders();

    vector<sf::Drawable *> ui;
    initUI(ui);
    int resp = 1;
    int skip = 0;
    do
    {

        if (this->map->checkIfEnd() != 94)
        {
            resp = 0;
        }
        else
        {
            if (skip == 0)
            {
                cout << "Continue:" << endl
                     << "1. Yes \n2. Fast Forward 100 rounds" << endl;
                cin >> resp;

                if (resp == 2)
                {
                    skip += 100;
                    resp = 1;
                }
                else if (resp != 1)
                {
                    break;
                }

                // clear buffer
                cin.ignore(30, '\n');
            }
            else
            {
                skip--;
            }
        }
        round(&window, ui);
    } while (resp == 1);

    int colour = this->map->checkIfEnd();
    cout << "---------------------------------------------------------------" << endl;

    this->map->printMap();

    cout << "---------------------------------------------------------------" << endl;
    if (colour == 94)
    {
        dynamic_cast<sf::Text *>(ui.at(4))->setString("WAR ENDS WITH PEACE TREATY");
        cout << "WAR ENDS WITH PEACE TREATY" << endl;
    }
    else
    {
        if (colour == this->groupOne->getColour())
        {
            dynamic_cast<sf::Text *>(ui.at(4))->setString("WAR ENDS WITH " + this->groupOne->getName() + " AS THE GLOBAL SUPERPOWER");
            cout << "WAR ENDS WITH " << this->groupOne->getName() << " AS THE GLOBAL SUPERPOWER" << endl;
        }
        else
        {
            dynamic_cast<sf::Text *>(ui.at(4))->setString("WAR ENDS WITH " + this->groupTwo->getName() + " AS THE GLOBAL SUPERPOWER");
            cout << "WAR ENDS WITH " << this->groupTwo->getName() << " AS THE GLOBAL SUPERPOWER" << endl;
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        map->draw(&window, NULL);
        for (int i = 0; i < ui.size(); i++)
        {
            window.draw(*ui.at(i));
        }
        window.display();
    }

    while (!ui.empty())
    {
        sf::Drawable *d = ui.back();
        delete d;
        ui.pop_back();
    }
}

void GUIOfWar::round(sf::RenderWindow *window, vector<sf::Drawable *> &ui)
{
    this->map->replenishAllPlatoons();
    /*
        First alliance turn
    */
    dynamic_cast<sf::Text *>(ui.at(4))->setString(groupOne->getName() + "'s turn");
    if (!this->real)
    {
        window->clear(sf::Color::Black);
        map->draw(window, NULL);
        for (int i = 0; i < ui.size(); i++)
        {
            window->draw(*(ui.at(i)));
        }

        window->display();
        this->checkTogglePlayer();
    }
    this->turn = true;

    this->takeTurn(this->map->getCountriesByColour(22).size() / 2 + 1, window, ui);

    this->map->resolveBattles();
    this->map->cleanBattles();

    if (this->map->checkIfEnd() != 94)
    {
        return;
    }
    this->map->replenishAllPlatoons();
    /*
        Second alliance turn
    */
    this->turn = false;
    dynamic_cast<sf::Text *>(ui.at(4))->setString(groupTwo->getName() + "'s turn");
    if (!this->real)
    {
        window->clear(sf::Color::Black);
        map->draw(window, NULL);
        for (int i = 0; i < ui.size(); i++)
        {
            window->draw(*(ui.at(i)));
        }
        window->display();
        this->checkTogglePlayer();
    }

    this->takeTurn(this->map->getCountriesByColour(160).size() / 2 + 1, window, ui);

    this->map->resolveBattles();
    this->map->cleanBattles();

    // this->map->toStringCount();
}

void GUIOfWar::checkTogglePlayer()
{
    if (this->player->changePlayer())
    {
        Player *temp = this->player->togglePlayer("guiUser");
        delete this->player;
        this->player = temp;
        this->map->setPlayer(this->player);
    }
}

void GUIOfWar::initialiseSides()
{

    const int WINDOW_X = 1280;
    const int WINDOW_Y = 640;
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Make Countries");
    cout << "--------------------------------------------------------------" << endl;
    cout << "INITIALISING SIDES" << endl;
    cout << "--------------------------------------------------------------" << endl;
    this->player->initialise(this->groupOne, this->groupTwo, this->map, &window);
}

void GUIOfWar::printMap()
{
    this->map->printMap();
}

void GUIOfWar::initUI(vector<sf::Drawable *> &ui)
{
    sf::Texture *displayTexture = new sf::Texture();
    if (!displayTexture->loadFromFile("../dalandTilesets/images/Display.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite *display = new sf::Sprite();
    display->setTexture(*(displayTexture));
    display->setPosition(666, 0);
    display->scale(2.8, 6.8);

    sf::Texture *moveBtnTexture = new sf::Texture();
    if (!moveBtnTexture->loadFromFile("../dalandTilesets/images/moveBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite *moveBtn = new sf::Sprite();
    moveBtn->setTexture(*moveBtnTexture);
    moveBtn->setPosition(666, 560);
    moveBtn->scale(3, 3);

    sf::Texture *buildBtnTexture = new sf::Texture();
    if (!buildBtnTexture->loadFromFile("../dalandTilesets/images/buildBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite *buildBtn = new sf::Sprite();
    buildBtn->setTexture(*buildBtnTexture);
    buildBtn->setPosition(762, 560);
    buildBtn->scale(3, 3);

    sf::Texture *destroyRouteBtnTexture = new sf::Texture();
    if (!destroyRouteBtnTexture->loadFromFile("../dalandTilesets/images/destroyRouteBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite *destroyRouteBtn = new sf::Sprite();
    destroyRouteBtn->setTexture(*destroyRouteBtnTexture);
    destroyRouteBtn->setPosition(858, 560);
    destroyRouteBtn->scale(4.174, 4.4);

    sf::Texture *recruitBtnTexture = new sf::Texture();
    if (!recruitBtnTexture->loadFromFile("../dalandTilesets/images/landPlatoon.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite *recruitBtn = new sf::Sprite();
    recruitBtn->setTexture(*recruitBtnTexture);
    recruitBtn->setPosition(954, 560);
    recruitBtn->scale(3, 3);

    sf::Texture *endTurnBtnTexture = new sf::Texture();
    if (!endTurnBtnTexture->loadFromFile("../dalandTilesets/images/endTurnBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite *endTurnBtn = new sf::Sprite();
    endTurnBtn->setTexture(*endTurnBtnTexture);
    endTurnBtn->setPosition(1200, 560);
    endTurnBtn->scale(4, 4);

    sf::Texture *inspectBtnTexture = new sf::Texture();
    if (!inspectBtnTexture->loadFromFile("../dalandTilesets/images/inspectBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite *inspectBtn = new sf::Sprite();
    inspectBtn->setTexture(*inspectBtnTexture);
    inspectBtn->setPosition(1050, 560);
    inspectBtn->scale(3.1, 3.1);

    sf::Text *text = new sf::Text();
    sf::Font *font = new sf::Font();
    if (!font->loadFromFile("../dalandTilesets/images/Terminus.ttf"))
    {
    }
    text->setFont(*font);
    text->setString("Hello world");
    text->setCharacterSize(12);
    text->setPosition(760, 20);

    ui.push_back(display);
    ui.push_back(moveBtn);
    ui.push_back(buildBtn);
    ui.push_back(endTurnBtn);
    ui.push_back(text);
    ui.push_back(destroyRouteBtn);
    ui.push_back(recruitBtn);
    ui.push_back(inspectBtn);
}

GUIOfWar::~GUIOfWar()
{
    /*
    Delete alliances
    */
    delete this->groupOne;
    delete this->groupTwo;

    /*
    Delete map
    */
    delete this->map;

    /*
    Delete player
    */
    delete this->player;

    /*
    Destroy ImageLibrary
    */
    ImageLibrary::DestroyInstance();
}