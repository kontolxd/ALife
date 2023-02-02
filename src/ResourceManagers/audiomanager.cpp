#include "ResourceManagers/audiomanager.h"

std::unordered_map<std::string, sf::SoundBuffer*> AudioManager::soundBuffers;

void AudioManager::load(std::string path)
{
    for(auto it : std::filesystem::directory_iterator(path))
    {
        soundBuffers[it.path().filename()] = new sf::SoundBuffer();
        soundBuffers[it.path().filename()]->loadFromFile(it.path());
    }
}

sf::SoundBuffer* AudioManager::get(std::string fileName)
{
    auto soundBuffer = AudioManager::soundBuffers.find(fileName);
    if(soundBuffer == soundBuffers.end())
    {
        //TODO!!!
        //Error log
        return nullptr;
    }
    else
    {
        return soundBuffer->second;
    }
}
