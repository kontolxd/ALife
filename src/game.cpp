#include "game.h"

Game::Game()
{
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
