#include "ResourceManagers/fontmanager.h"

std::unordered_map<std::string, sf::Font*> FontManager::fonts;

void FontManager::load(std::string path)
{
    for(auto it : std::filesystem::directory_iterator(path))
    {
        fonts[it.path().filename().string()] = new sf::Font();
        fonts[it.path().filename().string()]->loadFromFile(it.path().string());
    }
}

sf::Font* FontManager::get(std::string fileName)
{
    auto font = FontManager::fonts.find(fileName);
    if(font == fonts.end())
    {
        //TODO!!!
        //Error log
        return nullptr;
    }
    else
    {
        return font->second;
    }
}
