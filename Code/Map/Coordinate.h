#ifndef __COORDINATE_H__
#define __COORDINATE_H__
#include <SFML/Graphics.hpp>
#include <iostream>
class Area;
using namespace std;
class Coordinate
{

public:
    int x;
    int y;
    sf::Sprite* sprite=NULL;
    Area* area=NULL;

    Coordinate(int x, int y, int colour,Area* area);

    void setTextureBorders(string borders, int colour, bool terrain);

    void setCoordinateBorders(int x, int y, bool left, bool right, bool top, bool bottom);

    ~Coordinate();

    
};
#endif // __COORDINATE_H__