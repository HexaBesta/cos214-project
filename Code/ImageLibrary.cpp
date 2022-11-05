#include "ImageLibrary.h"

ImageLibrary *ImageLibrary::lib = nullptr;

ImageLibrary *ImageLibrary::getInstance()
{
    if (lib == nullptr)
    {
        lib = new ImageLibrary();
    }
    return lib;
}

void ImageLibrary::DestroyInstance(){
    delete lib;
}

ImageLibrary::ImageLibrary()
{
    cout << "Made one" << endl;
}

sf::Image *ImageLibrary::findTexture(string imageName)
{
    unordered_map<string, sf::Image *>::iterator itr = umap.find(imageName);
    if (itr == umap.end())
    {
        //cout << imageName << " not in map\n\n";
        sf::Image *img = new sf::Image();
        if (!img->loadFromFile(imageName))
        {
            cout << "Could not find Image" << endl;
        }
        umap.insert(make_pair(imageName, img));
        return img;
    }
    else
    {
        return itr->second;
    }
}

ImageLibrary::~ImageLibrary()
{
    unordered_map<string, sf::Image*>::iterator p;
    for (p = umap.begin();p != umap.end(); p++){
        delete p->second;   
    }
    umap.clear();
        
}