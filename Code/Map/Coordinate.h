#ifndef __COORDINATE_H__
#define __COORDINATE_H__
#include <SFML/Graphics.hpp>
class Coordinate
{

public:
    int x;
    int y;
    sf::Texture texture;
    sf::Sprite sprite;
    Coordinate(int x, int y, int colour)
    {
        this->x = x;
        this->y = y;
        sprite.setPosition(sf::Vector2f(x * 0.5 * 64, y * 0.5 * 64));

        if (colour == 22)
        {
            if (!texture.loadFromFile("../dalandTilesets/images/DesertTile_370_22.png"))
            {
                cout << "Texture missing" << endl;
            }
        }
        else if (colour == 160)
        {
            if (!texture.loadFromFile("../dalandTilesets/images/DesertTile_370_160.png"))
            {
                cout << "Texture missing" << endl;
            }
        }
        else
        {
            if (!texture.loadFromFile("../dalandTilesets/images/DesertTile_370_94.png"))
            {
                cout << "Texture missing" << endl;
            }
        }

        texture.setSmooth(true);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
        sprite.scale(0.5, 0.5);
    }

    void setTextureBorders(string borders,int colour)
    {
        if (!texture.loadFromFile("../dalandTilesets/images/DesertTile_370_"+to_string(colour)+"_"+borders+".png"))
        {
            cout << "Texture missing" << endl;
        }
        texture.setSmooth(true);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    }
};
#endif // __COORDINATE_H__