#include "game.h"

Game::Game()
{
    formManager = new FormManager();
    mainWindow = formManager->getMainWindow();
    LanguageManager::load("test");
    std::cout<<LanguageManager::get("greet")<<std::endl;
}

void Game::run()
{
    while(mainWindow->isOpen())
    {
        formManager->update();
    }
}
