#pragma once

#include <SFML/Graphics.hpp>

#include "Forms/formmanager.h"
#include "Forms/mainmenuform.h"
#include "Forms/consoleform.h"

#include "ResourceManagers/languagemanager.h"
#include "ResourceManagers/fontmanager.h"
#include "Events/eventmanager.h"

class Game
{
private:
    FormManager *mainFormManager;
    //FormManager *consoleFormManager;
    sf::RenderWindow *mainWindow;
    sf::RenderWindow *consoleWindow;
public:
    Game();
    void run();
};
