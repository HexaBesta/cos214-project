#include "Battle.h"
#include "Area.h"
#include "GUIUser.h"

bool GUIUser::playerRetreat(Battle *battle)
{
    // battle->getStateSummary();

    const int WINDOW_X = 222;
    const int WINDOW_Y = 39;
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Retreat?");

    // Create Land Button
    sf::Texture okayBtnTexture;
    if (!okayBtnTexture.loadFromFile("../Data/dalandTilesets/images/okayBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite okayBtn;
    okayBtn.setTexture(okayBtnTexture);
    okayBtn.setPosition(0, 0);
    okayBtn.scale(3, 3);

    // Create air button
    sf::Texture cancelBtnTexture;
    if (!cancelBtnTexture.loadFromFile("../Data/dalandTilesets/images/cancelBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite cancelBtn;
    cancelBtn.setTexture(cancelBtnTexture);
    cancelBtn.setPosition(111, 0);
    cancelBtn.scale(3, 3);
    int resp = -1;
    while (resp == -1)
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2f mouseClick = window.mapPixelToCoords(sf::Mouse::getPosition(window));
               

                if (okayBtn.getGlobalBounds().contains(mouseClick))
                {
                    resp = 1;
                }
                if (cancelBtn.getGlobalBounds().contains(mouseClick))
                {
                    resp = 0;
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(okayBtn);
        window.draw(cancelBtn);
        window.display();
    }
    window.close();

    if (resp == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GUIUser::checkChangeStrategy(Unit *active)
{
    // active->print();
    const int WINDOW_X = 222;
    const int WINDOW_Y = 39;
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Strat Change?");

    // Create Land Button
    sf::Texture okayBtnTexture;
    if (!okayBtnTexture.loadFromFile("../Data/dalandTilesets/images/okayBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite okayBtn;
    okayBtn.setTexture(okayBtnTexture);
    okayBtn.setPosition(0, 0);
    okayBtn.scale(3, 3);

    // Create air button
    sf::Texture cancelBtnTexture;
    if (!cancelBtnTexture.loadFromFile("../Data/dalandTilesets/images/cancelBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite cancelBtn;
    cancelBtn.setTexture(cancelBtnTexture);
    cancelBtn.setPosition(111, 0);
    cancelBtn.scale(3, 3);
    int resp = -1;
    while (resp == -1)
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2f mouseClick = window.mapPixelToCoords(sf::Mouse::getPosition(window));
               
                if (okayBtn.getGlobalBounds().contains(mouseClick))
                {
                    resp = 1;
                }
                if (cancelBtn.getGlobalBounds().contains(mouseClick))
                {
                    resp = 0;
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(okayBtn);
        window.draw(cancelBtn);
        window.display();
    }
    window.close();

    if (resp == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GUIUser::requestReinforcements(Battle *battle)
{

    const int WINDOW_X = 222;
    const int WINDOW_Y = 39;
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Reinforcements?");

    // Create Land Button
    sf::Texture okayBtnTexture;
    if (!okayBtnTexture.loadFromFile("../Data/dalandTilesets/images/okayBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite okayBtn;
    okayBtn.setTexture(okayBtnTexture);
    okayBtn.setPosition(0, 0);
    okayBtn.scale(3, 3);

    // Create air button
    sf::Texture cancelBtnTexture;
    if (!cancelBtnTexture.loadFromFile("../Data/dalandTilesets/images/cancelBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite cancelBtn;
    cancelBtn.setTexture(cancelBtnTexture);
    cancelBtn.setPosition(111, 0);
    cancelBtn.scale(3, 3);
    int resp = -1;
    while (resp == -1)
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2f mouseClick = window.mapPixelToCoords(sf::Mouse::getPosition(window));
               
                if (okayBtn.getGlobalBounds().contains(mouseClick))
                {
                    resp = 1;
                }
                if (cancelBtn.getGlobalBounds().contains(mouseClick))
                {
                    resp = 0;
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(okayBtn);
        window.draw(cancelBtn);
        window.display();
    }
    window.close();

    if (resp == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int GUIUser::chooseCountry(vector<Country *> country, Map *map, sf::RenderWindow *window, vector<sf::Drawable *> ui)
{
    do
    {
        sf::Font font;
        if (!font.loadFromFile("../Data/dalandTilesets/images/Terminus.ttf"))
        {
        }

        // create prompt text
        sf::Text promptText;
        promptText.setFont(font);
        promptText.setString("Choose country to take action");
        promptText.setCharacterSize(12);
        promptText.setPosition(760, 20);
        Country *c = chooseAreaForAction(window, map,"Choose country to take action", ui)->getCountry();
        for (int i = 0; i < country.size(); i++)
        {
            if (country.at(i) == c)
            {
                return i;
            }
        }
        cout << "Invalid country" << endl;
    } while (true);

    return -1;
}

int GUIUser::chooseActionForCountry(Area *area, Map *map, sf::RenderWindow *window, vector<sf::Drawable *>& ui)
{

    // cout << "Choose action to perform: \n 0 - march in \n 1 - destroy transport \n 2 - request transport factories \n 3 - recruit troops\n 4 - end turn" << endl;

    dynamic_cast<sf::Text *>(ui.at(4))->setString("Select an action for " + area->getName());
    int action = -1;
    while (action == -1)
    {

        sf::Event event;
        while (window->pollEvent(event))
        {

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2f mouseClick = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
               

                if (dynamic_cast<sf::Sprite *>(ui.at(1))->getGlobalBounds().contains(mouseClick))
                {
                    action = 0;
                }
                if (dynamic_cast<sf::Sprite *>(ui.at(5))->getGlobalBounds().contains(mouseClick))
                {
                    action = 1;
                }
                if (dynamic_cast<sf::Sprite *>(ui.at(2))->getGlobalBounds().contains(mouseClick))
                {
                    action = 2;
                }
                if (dynamic_cast<sf::Sprite *>(ui.at(6))->getGlobalBounds().contains(mouseClick))
                {
                    action = 3;
                }
                if (dynamic_cast<sf::Sprite *>(ui.at(3))->getGlobalBounds().contains(mouseClick))
                {
                    action = 4;
                    dynamic_cast<sf::Text *>(ui.at(4))->setString("Turn skipped");
                }
                if (dynamic_cast<sf::Sprite *>(ui.at(7))->getGlobalBounds().contains(mouseClick))
                {
                    action = 5;
                    dynamic_cast<sf::Text *>(ui.at(4))->setString("Choose area to inspect");
                }
            }
        }

        window->clear(sf::Color::Black);
        map->draw(window, NULL);
        for (int i = 0; i < ui.size(); i++)
        {
            window->draw(*ui.at(i));
        }
        window->display();
    }

    return action;
}

Area *GUIUser::chooseAdjacentArea(vector<Area *> areas, Area *area, sf::RenderWindow *window, vector<sf::Drawable *> ui, Map *map)
{

    return chooseAreaForAction(window, map, "Select area to move to", ui);
}

int *GUIUser::chooseAreasToDestroyTransportRoutes(vector<Area *> adjAreas, vector<vector<Area *>> otherAdj, Area *current, sf::RenderWindow *window, vector<sf::Drawable *> ui, Map *map)
{
    int *indexes = new int[2];
    indexes[0] = indexes[1] = -1;
    int areaIndex = -1;
    Area *selected1 = this->chooseAdjacentArea(adjAreas,current,window,ui,map);
    for (int i = 0; i < adjAreas.size(); i++)
    {
        if (adjAreas.at(i) == selected1)
            areaIndex = i;
    }

    indexes[0] = areaIndex;
    areaIndex = -1;
    if (indexes[0] != -1 && indexes[0] < otherAdj.size())
    {
        Area *selected2 = this->chooseAdjacentArea(otherAdj.at(indexes[0]),current,window,ui,map);
        for (int i = 0; i < otherAdj.at(indexes[0]).size(); i++)
        {
            if (otherAdj.at(indexes[0]).at(i) == selected2)
                areaIndex = i;
        }
        indexes[1] = areaIndex;
        if (indexes[1] != -1 && indexes[1] < otherAdj.at(indexes[0]).size())
        {
            return indexes;
        }
    }
    delete[] indexes;
    indexes = NULL;
    return NULL;
}

int GUIUser::chooseResource(Area *area)
{
    cout << "Choose what resource to request for area: \n 0 - Medics  \n 1 - Ammo \n 2 - Goods" << endl;
    const int WINDOW_X = 207;
    const int WINDOW_Y = 54;
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Choose Platoon type");

    // Create medic Button
    sf::Texture medicBtnTexture;
    if (!medicBtnTexture.loadFromFile("../Data/dalandTilesets/images/medicBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite medicBtn;
    medicBtn.setTexture(medicBtnTexture);
    medicBtn.setPosition(0, 0);
    medicBtn.scale(3, 3);

    // Create ammo button
    sf::Texture ammoBtnTexture;
    if (!ammoBtnTexture.loadFromFile("../Data/dalandTilesets/images/ammoBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite ammoBtn;
    ammoBtn.setTexture(ammoBtnTexture);
    ammoBtn.setPosition(69, 0);
    ammoBtn.scale(3, 3);

    // Create goods button
    sf::Texture goodsBtnTexture;
    if (!goodsBtnTexture.loadFromFile("../Data/dalandTilesets/images/goodsBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite goodsBtn;
    goodsBtn.setTexture(goodsBtnTexture);
    goodsBtn.setPosition(138, 0);
    goodsBtn.scale(3, 3);
    int resp = -1;
    while (resp == -1)
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2f mouseClick = window.mapPixelToCoords(sf::Mouse::getPosition(window));
               

                if (medicBtn.getGlobalBounds().contains(mouseClick))
                {
                    resp = 0;
                }
                if (ammoBtn.getGlobalBounds().contains(mouseClick))
                {
                    resp = 1;
                }
                if (goodsBtn.getGlobalBounds().contains(mouseClick))
                {
                    resp = 2;
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(medicBtn);
        window.draw(ammoBtn);
        window.draw(goodsBtn);
        window.display();
    }
    if (area->getFactory(resp) == nullptr)
    {
        area->requestFactory(resp);
        return resp;
    }
    else
    {
        area->getFactory(resp);
        return resp;
    }
}

bool GUIUser::changePlayer()
{
    const int WINDOW_X = 222;
    const int WINDOW_Y = 39;
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Change Player");

    // Create Land Button
    sf::Texture okayBtnTexture;
    if (!okayBtnTexture.loadFromFile("../Data/dalandTilesets/images/okayBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite okayBtn;
    okayBtn.setTexture(okayBtnTexture);
    okayBtn.setPosition(0, 0);
    okayBtn.scale(3, 3);

    // Create air button
    sf::Texture cancelBtnTexture;
    if (!cancelBtnTexture.loadFromFile("../Data/dalandTilesets/images/cancelBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite cancelBtn;
    cancelBtn.setTexture(cancelBtnTexture);
    cancelBtn.setPosition(111, 0);
    cancelBtn.scale(3, 3);
    int resp = -1;
    while (resp == -1)
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2f mouseClick = window.mapPixelToCoords(sf::Mouse::getPosition(window));
              

                if (okayBtn.getGlobalBounds().contains(mouseClick))
                {
                    resp = 1;
                }
                if (cancelBtn.getGlobalBounds().contains(mouseClick))
                {
                    resp = 0;
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(okayBtn);
        window.draw(cancelBtn);
        window.display();
    }
    window.close();
    return resp;
}

Player *GUIUser::togglePlayer(string type)
{
    Player *togglePlayer = new CPU();
    return togglePlayer;
}

void GUIUser::createCountries(Map *map, sf::RenderWindow *window)
{
    // initialise window

    // draw map on window
    map->setAreaBorders();
    window->clear(sf::Color::Black);
    map->draw(window, NULL);
    window->display();

    // create font
    sf::Font font;
    if (!font.loadFromFile("../Data/dalandTilesets/images/Terminus.ttf"))
    {
    }

    // create prompt text
    sf::Text promptText;
    promptText.setFont(font);
    promptText.setString("How many countries would you like to initialise?");
    promptText.setCharacterSize(12);
    promptText.setPosition(760, 20);

    // Create output text
    sf::Text outputText;
    outputText.setFont(font);
    outputText.setString("How many countries would you like to initialise?");
    outputText.setCharacterSize(12);
    outputText.setPosition(760, 50);

    // Create input string
    string input = "";

    // create complete button
    sf::Texture confirmBtnTexture;
    if (!confirmBtnTexture.loadFromFile("../Data/dalandTilesets/images/endTurnBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite confirmBtn;
    confirmBtn.setTexture(confirmBtnTexture);
    confirmBtn.setPosition(1200, 500);
    confirmBtn.scale(4, 4);

    int guiResp = getInt(window, &promptText, &outputText, &confirmBtn, map);
    int resp = 0;
    cout << endl
         << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- " << endl;
    while (guiResp > 0)
    {
        string countryName = "";
        promptText.setString("Please enter country name:");
        countryName = getString(window, &promptText, &outputText, &confirmBtn, map);

        Country *country = new Country(countryName, 94, this);
        if (map == NULL)
        {
            cout << "Map is NULL in User" << endl;
        }
        map->addCountry(country);
        map->printMap();
        Area *area = NULL;
        do
        {

            promptText.setString("Where must " + country->getName() + " start?\n(Click area on Map)");
            area = chooseAreaForAction(window, map, "Where must " + country->getName() + " start?\n(Click area on Map)", {});
        } while (area == NULL || !area->setCountry(country));
        // cout<<"Country added to map"<<endl;
        guiResp--;
        map->setAreaBorders();
        window->clear(sf::Color::Black);
        map->draw(window, NULL);
        window->display();
    }
}

int GUIUser::numberOfCountriesInAlliance(Map *map, sf::RenderWindow *window)
{
    vector<Country *> country = map->getCountriesByColour(94);
    // initialise window

    // draw map on window
    map->setAreaBorders();
    window->clear(sf::Color::Black);
    map->draw(window, NULL);
    window->display();

    // create font
    sf::Font font;
    if (!font.loadFromFile("../Data/dalandTilesets/images/Terminus.ttf"))
    {
    }

    // create prompt text
    sf::Text promptText;
    promptText.setFont(font);
    promptText.setString("How many countries would you like to initialise?");
    promptText.setCharacterSize(12);
    promptText.setPosition(760, 20);

    // Create output text
    sf::Text outputText;
    outputText.setFont(font);
    outputText.setString("How many countries would you like to initialise?");
    outputText.setCharacterSize(12);
    outputText.setPosition(760, 50);

    // Create input string
    string input = "";

    // create complete button
    sf::Texture confirmBtnTexture;
    if (!confirmBtnTexture.loadFromFile("../Data/dalandTilesets/images/endTurnBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite confirmBtn;
    confirmBtn.setTexture(confirmBtnTexture);
    confirmBtn.setPosition(1200, 500);
    confirmBtn.scale(4, 4);
    promptText.setString("The number of countries that are neutral " + to_string(country.size()) + "\n Choose the amount you want to join your alliance: ");
    int guiResp = getInt(window, &promptText, &outputText, &confirmBtn, map);
    return guiResp;
}

Country *GUIUser::chooseCountryToJoinAlliance(Map *map, sf::RenderWindow *window)
{
    vector<Country *> country = map->getCountriesByColour(94);

    // initialise window

    // draw map on window
    map->setAreaBorders();
    window->clear(sf::Color::Black);
    map->draw(window, NULL);
    window->display();

    Area *selected = chooseAreaForAction(window, map, "Choose a country to join alliance.\n(Click an area on the map)", {});
    return selected->getCountry();
}

void GUIUser::addPlatoons(Country *country, Map *map, sf::RenderWindow *window,vector<sf::Drawable*> ui)
{
    country->recruitPlatoon(map, window,ui);
}

void GUIUser::initialiseFactories(Map *map, Alliances *alliances)
{
    vector<Area *> areas = map->getAreasByColour(alliances->getColour());
    map->printMap();
    cout << "Choose area to create factory in: " << endl;
    int x = 0;
    for (auto it : areas)
    {
        cout << it->getName() << " (" << it->getIndex() << ")"
             << "|| Index: " << x << endl;
        x++;
    }
    int resp = 0;
    cin >> resp;
    cout << "Now choose what factory you want to create at the chosen area: \n0 - Medics\n1 - Ammo\n2 - Goods" << endl;
    int resp1 = 0;
    cin >> resp1;
    map->requestFactoryForArea(areas.at(resp), resp1);
}

int GUIUser::platoonType()
{
    const int WINDOW_X = 192;
    const int WINDOW_Y = 81;
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Choose Platoon type");
    window.setPosition(sf::Vector2i(1000,500));
    // Create Land Button
    sf::Texture landPlatoonBtnTexture;
    if (!landPlatoonBtnTexture.loadFromFile("../Data/dalandTilesets/images/landPlatoon.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite landPlatoonBtn;
    landPlatoonBtn.setTexture(landPlatoonBtnTexture);
    landPlatoonBtn.setPosition(0, 0);
    landPlatoonBtn.scale(3, 3);

    // Create air button
    sf::Texture airPlatoonBtnTexture;
    if (!airPlatoonBtnTexture.loadFromFile("../Data/dalandTilesets/images/airPlatoon.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite airPlatoonBtn;
    airPlatoonBtn.setTexture(airPlatoonBtnTexture);
    airPlatoonBtn.setPosition(96, 0);
    airPlatoonBtn.scale(3, 3);
    int resp = -1;
    while (resp == -1)
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2f mouseClick = window.mapPixelToCoords(sf::Mouse::getPosition(window));
               

                if (landPlatoonBtn.getGlobalBounds().contains(mouseClick))
                {
                    resp = 1;
                }
                if (airPlatoonBtn.getGlobalBounds().contains(mouseClick))
                {
                    resp = 0;
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(landPlatoonBtn);
        window.draw(airPlatoonBtn);
        window.display();
    }
    window.close();
    return resp;
}

void GUIUser::inspect(Map *map)
{
    int resp = 0;
    do
    {
        cout << "-------------------------------------------------------" << endl;
        cout << "Would you like to inspect an area?\n1. Yes \n2. No" << endl;
        cin >> resp;
        if (resp == 1)
        {
            cout << endl
                 << "Which area would you like to inspect? ";
            cin >> resp;
            Area *area = map->getAreaByIndex(resp);
            if (area != NULL)
            {
                cout << area->toString();
            }
        }
    } while (resp != 2);
}

string GUIUser::getString(sf::RenderWindow *window, sf::Text *prompt, sf::Text *output, sf::Sprite *confirmBtn, Map *map)
{
    bool clicked = false;
    string input = "";
    output->setString(input);
    while (!clicked)
    {

        sf::Event event;
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            // if (event.type == sf::Event::KeyPressed)
            // {
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    input += static_cast<char>(event.text.unicode);
                    output->setString(input);
                }
                cout << "text" << endl;
            }
            // }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2f mouseClick = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
           
                if (confirmBtn->getGlobalBounds().contains(mouseClick))
                {
                    clicked = true;
                }
            }
        }

        window->clear(sf::Color::Black);
        map->draw(window, NULL);
        window->draw(*prompt);
        window->draw(*output);
        window->draw(*confirmBtn);
        window->display();
    }
    output->setString("");
    return input;
}

int GUIUser::getInt(sf::RenderWindow *window, sf::Text *prompt, sf::Text *output, sf::Sprite *confirmBtn, Map *map)
{
    bool clicked = false;
    string input = "";
    output->setString(input);
    while (!clicked)
    {

        sf::Event event;
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            // if (event.type == sf::Event::KeyPressed)
            // {
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode <= 57 && event.text.unicode >= 48)
                {
                    input += static_cast<char>(event.text.unicode);
                    output->setString(input);
                }
            }
            // }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2f mouseClick = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
              

                if (confirmBtn->getGlobalBounds().contains(mouseClick))
                {
                    clicked = true;
                }
            }
        }

        window->clear(sf::Color::Black);
        map->draw(window, NULL);
        window->draw(*prompt);
        window->draw(*output);
        window->draw(*confirmBtn);
        window->display();
    }
    output->setString("");
    return stoi(input);
}

Area *GUIUser::chooseAreaForAction(sf::RenderWindow *window, Map *map, string prompt, vector<sf::Drawable *> ui)
{
    sf::Text promptText;
    sf::Font font;
    if (ui.size() < 0)
    {
        dynamic_cast<sf::Text *>(ui.at(4))->setString(prompt);
    }
    else
    {
        
        if (!font.loadFromFile("../Data/dalandTilesets/images/Terminus.ttf"))
        {
        }

        // create prompt text
        sf::Text promptText;
        promptText.setFont(font);
        promptText.setString(prompt);
        promptText.setCharacterSize(12);
        promptText.setPosition(760, 20);
    }

    Area *selected = NULL;
    while (selected == NULL)
    {

        sf::Event event;
        while (window->pollEvent(event))
        {

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2f mouseClick = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
              

                selected = map->getAreaClicked(mouseClick);
            }
        }

        window->clear(sf::Color::Black);
        map->draw(window, NULL);
        for (int i = 0; i < ui.size(); i++)
        {
            window->draw(*(ui.at(i)));
        }
        if (ui.size()==0)
        {
            window->draw(promptText);
        }
        
        window->display();
    }
    return selected;
}

Area *GUIUser::chooseAreaForAction(vector<Area *> areas, sf::RenderWindow *window, Map *map, vector<sf::Drawable *> ui)
{

    int resp = 0;
    Area *selected = NULL;
    while (selected == NULL)
    {

        sf::Event event;
        while (window->pollEvent(event))
        {

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2f mouseClick = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
                

                selected = map->getAreaClicked(mouseClick);
            }
        }

        window->clear(sf::Color::Black);
        map->draw(window, NULL);
        for (int i = 0; i < ui.size(); i++)
        {
            window->draw(*ui.at(i));
        }

        window->display();
    }
    return selected;
}
