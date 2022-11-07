#ifndef IMAGELIBRARY_H
#define IMAGELIBRARY_H
#include <unordered_map>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class ImageLibrary
{
private:
    unordered_map<string, sf::Image*> umap;
    static ImageLibrary* lib;

    ImageLibrary();

    ~ImageLibrary();
    
public:

    static ImageLibrary* getInstance();

    static void DestroyInstance();

    sf::Image *findTexture(string imageName);
};



#endif