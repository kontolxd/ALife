#pragma once
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>
#include <string>
#include <unordered_map>

class FontManager
{
private:
    // static void printInfo(void (*callback)(std::string info));
    static std::unordered_map<std::string, sf::Font*> fonts;
public:
    FontManager() = delete;
    static void load(std::string path = "./res/Fonts");
    static sf::Font* get(std::string filename);
};
