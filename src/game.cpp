#include "game.h"

Game::Game()
{
    LanguageManager::load("test");
    FontManager::load();
    formManager = new FormManager();
    mainWindow = formManager->getMainWindow();
}

void Game::run()
{
    while(mainWindow->isOpen())
    {
        formManager->update();
    }
}
