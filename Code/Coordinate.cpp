#include "Coordinate.h"

Coordinate::Coordinate(int x, int y, int colour,Area* area,int scaleX,int scaleY)
    {
        this->area = area;
        this->x = x;
        this->y = y;
        sprite.setPosition(sf::Vector2f(x * (640/scaleX), y * (640/scaleY)));

        if (colour == 22)
        {
            if (!texture.loadFromFile("../dalandTilesets/images/DesertTile_370_22_.png"))
            {
                cout << "Texture missing" << endl;
            }
        }
        else if (colour == 160)
        {
            if (!texture.loadFromFile("../dalandTilesets/images/DesertTile_370_160_.png"))
            {
                cout << "Texture missing" << endl;
            }
        }
        else if (colour == 0)
        {
            if (!texture.loadFromFile("../dalandTilesets/images/WaterTile_.png"))
            {
                cout << "Texture missing" << endl;
            }
        }
        else
        {
            if (!texture.loadFromFile("../dalandTilesets/images/DesertTile_370_94_.png"))
            {
                cout << "Texture missing" << endl;
            }
        }

        texture.setSmooth(true);
        // sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
        sprite.scale((640/scaleX)/64.0, (640/scaleY)/64.0);
    }

    void Coordinate::setTextureBorders(string borders, int colour, bool terrain)
    {
        if (!terrain)
        {
            if (!texture.loadFromFile("../dalandTilesets/images/DesertTile_370_" + to_string(colour) + "_" + borders + ".png"))
            {
                cout << "Texture missing" << endl;
            }
        }
        else
        {
            if (!texture.loadFromFile("../dalandTilesets/images/WaterTile_" + borders + ".png"))
            {
                cout << "Texture missing" << endl;
            }
        }

        texture.setSmooth(true);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    }

    void Coordinate::setCoordinateBorders(int x, int y, bool left,bool leftCon, bool right, bool rightCon, bool top, bool topCon, bool bottom,bool bottomCon)
    {

        string borders = "";
        if (left)
        {
             borders+="Left";
        }
        if (leftCon)
        {
            borders+="C";
        }
        
        if (right)
        {
             borders+="Right";
        }
        if (rightCon)
        {
            borders+="C";
        }
        if (top)
        {
             borders+="Top";
        }
        if (topCon)
        {
            borders+="C";
        }
        if (bottom)
        {
             borders+="Bottom";
        }
        if (bottomCon)
        {
            borders+="C";
        }
        setTextureBorders(borders, 0, true);
        return;
    }