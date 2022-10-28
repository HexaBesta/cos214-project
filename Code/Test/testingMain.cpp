#include <SFML/Graphics.hpp>
#include "../Map/Map.h"
#include "../Map/Area.h"
#include "../Builder/Director.h"
#include "../Country/Country.h"

using namespace std;

void testEuropeMap()
{
    Map *m = new Map("../Maps/europe.txt");

    m->printMap();
    cout << (m->getAreaByIndex(6)->toString()) << endl;
    cout << (m->getAreaByIndex(7)->toString()) << endl;

    cout <<"Status of factory request: "<< m->getAreaByIndex(7)->requestFactory(1) << endl;
    cout << (m->getAreaByIndex(7)->toString()) << endl;

    m->createTransportRoute(m->getAreaByIndex(6),m->getAreaByIndex(7));

    cout <<"Status of factory request: "<< m->getAreaByIndex(7)->requestFactory(0) << endl;
    cout << (m->getAreaByIndex(7)->toString()) << endl;

    m->createTransportRoute(m->getAreaByIndex(6),m->getAreaByIndex(8));
    cout <<"Status of factory request: "<< m->getAreaByIndex(8)->requestFactory(1) << endl;
    cout << (m->getAreaByIndex(8)->toString()) << endl;

    cout << (m->getAreaByIndex(4)->toString()) << endl;

    cout << (m->getAreaByIndex(5)->toString()) << endl;

    m->getAreaByIndex(4)->marchOut(m->getAreaByIndex(5));

    cout << (m->getAreaByIndex(4)->toString()) << endl;

    cout << (m->getAreaByIndex(5)->toString()) << endl;

    m->printMap();
    cout << (m->getAreaByIndex(5)->toString()) << endl;
    cout <<"Status of factory request: "<< m->getAreaByIndex(5)->requestFactory(2) << endl;
    cout << (m->getAreaByIndex(5)->toString()) << endl;
    m->printMap();

    cout << (m->getAreaByIndex(5)->toString()) << endl;

    cout << (m->getAreaByIndex(8)->toString()) << endl;

    m->getAreaByIndex(5)->marchOut(m->getAreaByIndex(8));

    cout << (m->getAreaByIndex(5)->toString()) << endl;

    cout << (m->getAreaByIndex(8)->toString()) << endl;

    m->printMap();

    cout << (m->getAreaByIndex(6)->toString()) << endl;

    cout << (m->getAreaByIndex(10)->toString()) << endl;

    m->getAreaByIndex(6)->marchOut(m->getAreaByIndex(10));

    cout << (m->getAreaByIndex(6)->toString()) << endl;

    cout << (m->getAreaByIndex(10)->toString()) << endl;

    m->printMap();

    cout << (m->getAreaByIndex(6)->toString()) << endl;

    cout << (m->getAreaByIndex(7)->toString()) << endl;

    m->getAreaByIndex(6)->marchOut(m->getAreaByIndex(7));

    cout << (m->getAreaByIndex(6)->toString()) << endl;

    cout << (m->getAreaByIndex(7)->toString()) << endl;

    m->printMap();

    //Added test - Inge (Retreat)

    m->getAreaByIndex(7)->retreat("defense");
    cout << (m->getAreaByIndex(6)->toString()) << endl;

    cout << (m->getAreaByIndex(7)->toString()) << endl;
    m->printMap();

    delete m;
}

void testMap1()
{
    Map *m = new Map("../Maps/map1.txt");
    m->createTransportRoute(m->getAreaByIndex(1), m->getAreaByIndex(2));
    m->createTransportRoute(m->getAreaByIndex(0), m->getAreaByIndex(2));
    m->createTransportRoute(m->getAreaByIndex(1), m->getAreaByIndex(3));
    m->createTransportRoute(m->getAreaByIndex(5), m->getAreaByIndex(3));
    m->printMap();

    for (size_t i = 0; i < 6; i++)
    {
        m->listAdjacent(m->getAreaByIndex(i), false);
    }

    delete m;
}

void testBuilder() {
    Director* terrorist = new Director();
    Country* c = new Country("Sandton", 22);

    Unit* teetee = terrorist->construct(true, c);
    cout << teetee->toString() << endl;

    cout << "-------------" << endl;

    teetee = terrorist->construct(true, c);
    cout << teetee->toString() << endl;

        cout << "-------------" << endl;

    teetee = terrorist->construct(true, c);
    cout << teetee->toString() << endl;

            cout << "-------------" << endl;

    teetee = terrorist->construct(true, c);
    cout << teetee->toString() << endl;

    delete terrorist;
    delete c;
    delete teetee;
}

void testGui()
{

    Map *m = new Map("../Maps/europe.txt");
    // m->printMap();

    const int WINDOW_X = 1280;
    const int WINDOW_Y = 640;
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "My window");

    sf::Texture displayTexture;
    if (!displayTexture.loadFromFile("../dalandTilesets/images/Display.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite display;
    display.setTexture(displayTexture);
    display.setPosition(666, 0);
    display.scale(2.8, 3);

    sf::Texture moveBtnTexture;
    if (!moveBtnTexture.loadFromFile("../dalandTilesets/images/moveBtn.png"))
    {
        cout << "Texture missing" << endl;
    }
    sf::Sprite moveBtn;
    moveBtn.setTexture(moveBtnTexture);
    moveBtn.setPosition(666, 300);
    moveBtn.scale(3, 3);

    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("../dalandTilesets/images/Terminus.ttf"))
    {
    }
    text.setFont(font);
    text.setString("Hello world");
    text.setCharacterSize(12);
    text.setPosition(760, 20);

    bool moving = false;
    int c = 0;
    Area *selectedArea = NULL;

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

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2f mouseClick = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                cout << "clicked " << c++ << endl;

                if (!moving)
                {
                    Area* temp = m->getAreaClicked(mouseClick);
                    if (temp != NULL)
                    {
                        selectedArea=temp;
                        cout << selectedArea->toString() << endl;
                        text.setString(selectedArea->toString());
                    }
                    else
                    {
                        cout << "No area clicked" << endl;
                    }
                }else{
                    Area* marchInto=m->getAreaClicked(mouseClick);
                    if(selectedArea==NULL){
                        cout << "No selected area to march out of" << endl;
                    }else if(marchInto==NULL){
                        cout << "No selected area to march into" << endl;
                    }else{
                         selectedArea->marchOut(marchInto);
                         moving=false;
                    }
                }

                if (moveBtn.getGlobalBounds().contains(mouseClick))
                {
                    moving = true;
                    cout<<"Clicked moveBtn"<<endl;
                }
            }
        }

        window.clear(sf::Color::Black);

        m->draw(&window);
        window.draw(display);
        window.draw(text);
        window.draw(moveBtn);
        window.display();
    }
    delete m;
}

int main()
{

    // testMap1();
    // cout << endl
    //      << endl;
    // testEuropeMap();

    // testBuilder();

    testGui();
}
