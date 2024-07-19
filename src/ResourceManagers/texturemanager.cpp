#include "ResourceManagers/texturemanager.h"

std::unordered_map<std::string, sf::Texture*> TextureManager::textures;

void TextureManager::load(std::string path)
{
    for(auto it : std::filesystem::directory_iterator(path))
    {
        textures[it.path().filename().string()] = new sf::Texture();
        textures[it.path().filename().string()]->loadFromFile(it.path().string());
    }
}

sf::Texture* TextureManager::get(std::string fileName)
{
    auto texture = TextureManager::textures.find(fileName);
    if(texture == textures.end())
    {
        //TODO!!!
        //Error log
        return nullptr;
    }
    else
    {
        return texture->second;
    }
}
