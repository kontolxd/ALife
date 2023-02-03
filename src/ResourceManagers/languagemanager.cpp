#include "ResourceManagers/languagemanager.h"

std::unordered_map<std::string, std::string> LanguageManager::languageMap;

void LanguageManager::load(std::string language, std::string path)
{
    languageMap.clear();
    std::ifstream istream(path + "/" + language + ".lang");
    if(!istream)
    {
        //TODO Error log
        return;
    }
    std::string line, key;
    while(std::getline(istream, line))
    {
        if(line[0] == '[')
        {
            key = line.substr(1, line.size() - 2);
            languageMap[key] = "";
        }
        else if(line[0] == '/' && line[1] == '[')
        {
            key.clear();
        }
        else if(!key.empty())
        {
            languageMap[key] += line + '\n';
        }
    }
}

std::string& LanguageManager::get(std::string key)
{
    auto it = languageMap.find(key);
    if(it == languageMap.end())
    {
        //TODO error log
    }
    else
    {
        return it->second;
    }
}
