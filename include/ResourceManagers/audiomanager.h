#pragma once
#include <SFML/Audio.hpp>
#include <filesystem>
#include <iostream>
#include <unordered_map>

class AudioManager
{
private:
    static std::unordered_map<std::string, sf::SoundBuffer*> soundBuffers;
public:
    AudioManager() = delete;
    static void load(std::string path = "./res/Audio");
    static sf::SoundBuffer* get(std::string fileName);
};
