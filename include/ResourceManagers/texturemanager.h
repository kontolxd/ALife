#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <filesystem>
#include <string>

class TextureManager
{
private:
    static std::unordered_map<std::string, sf::Texture*> textures;
public:
    TextureManager() = delete;
    static void load(std::string path = "./res/Textures");
    static sf::Texture* get(std::string fileName);
};
