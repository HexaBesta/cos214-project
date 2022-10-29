// #include "Coordinate.h"

// Coordinate::Coordinate(int x, int y, int colour, Area *area)
// {
//     this->area = area;
//     this->x = x;
//     this->y = y;
//     sprite = new sf::Sprite();
//     texture= new sf::Texture();
    
//     sprite->setPosition(sf::Vector2f(x * 0.5 * 64, y * 0.5 * 64));

//         if (colour == 22)
//         {
//             if (!texture->loadFromFile("../dalandTilesets/images/DesertTile_370_22_.png"))
//             {
//                 cout << "Texture missing" << endl;
//             }
//         }
//         else if (colour == 160)
//         {
//             if (!texture->loadFromFile("../dalandTilesets/images/DesertTile_370_160_.png"))
//             {
//                 cout << "Texture missing" << endl;
//             }
//         }
//         else if (colour == 0)
//         {
//             if (!texture->loadFromFile("../dalandTilesets/images/WaterTile_.png"))
//             {
//                 cout << "Texture missing" << endl;
//             }
//         }
//         else
//         {
//             if (!texture->loadFromFile("../dalandTilesets/images/DesertTile_370_94_.png"))
//             {
//                 cout << "Texture missing" << endl;
//             }
//         }

//         texture->setSmooth(true);
//         // sprite->setTexture(*texture);
//         sprite->setTextureRect(sf::IntRect(0, 0, 64, 64));
//         sprite->scale(0.5, 0.5);
// }

// void Coordinate::setTextureBorders(string borders, int colour, bool terrain)
// {
//     sf::Texture *texture = new sf::Texture();
//     if (!terrain)
//     {
//         if (!texture->loadFromFile("../dalandTilesets/images/DesertTile_370_" + to_string(colour) + "_" + ".png"))
//         {
//             cout << "Texture missing" << endl;
//         }
//     }
//     else
//     {
//         if (!texture->loadFromFile("../dalandTilesets/images/WaterTile_" + borders + ".png"))
//         {
//             cout << "Texture missing" << endl;
//         }
//     }

//     texture->setSmooth(true);
//     sprite->setTexture(*(texture));
//     sprite->setTextureRect(sf::IntRect(0, 0, 64, 64));
// }

// void Coordinate::setCoordinateBorders(int x, int y, bool left, bool right, bool top, bool bottom)
// {

//     string borders = "";
//     if (left)
//     {
//         borders += "Left";
//     }
//     if (right)
//     {
//         borders += "Right";
//     }
//     if (top)
//     {
//         borders += "Top";
//     }
//     if (bottom)
//     {
//         borders += "Bottom";
//     }
//     setTextureBorders(borders, 0, true);
//     return;
// }

// Coordinate::~Coordinate()
// {
    
//     delete sprite;
//     delete texture;
// }
