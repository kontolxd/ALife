#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

class LanguageManager
{
private:
    static std::unordered_map<std::string, std::string> languageMap;
public:
    LanguageManager() = delete;
    static void load(std::string lang = "english", std::string path = "./res/Languages");
    static std::string& get(std::string key);
};
