#include "game.h"

Game::Game()
{
    formManager = new FormManager();
    mainWindow = formManager->getMainWindow();
    LanguageManager::load("test");
}

void Game::run()
{
    while(mainWindow->isOpen())
    {
        formManager->update();
    }
}
