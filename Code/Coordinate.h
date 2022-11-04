#ifndef __COORDINATE_H__
#define __COORDINATE_H__
#include <SFML/Graphics.hpp>
#include <iostream>

#include "ImageLibrary.h"
class Area;
using namespace std;
class Coordinate
{

public:
    int x;
    int y;
    sf::Texture texture;
    sf::Sprite sprite;
    Area* area=NULL;

    Coordinate(int x, int y, int colour,Area* area,int scaleX,int scaleY);

    void setTextureBorders(string borders, int colour, bool terrain);

    void setCoordinateBorders(int x, int y, bool left,bool leftCon, bool right, bool rightCon, bool top, bool topCon, bool bottom,bool bottomCon);

    //~Coordinate();

    
};
#endif // __COORDINATE_H__