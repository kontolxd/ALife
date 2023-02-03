#pragma once
#include <SFML/Graphics.hpp>
#include "Forms/formmanager.h"
#include "ResourceManagers/languagemanager.h"
#include "Events/eventmanager.h"

class Game
{
private:
    FormManager *formManager;
    sf::RenderWindow *mainWindow;
public:
    Game();
    void run();
};
