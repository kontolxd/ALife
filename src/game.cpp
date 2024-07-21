#include "game.h"

Game::Game()
{
    LanguageManager::load("test");
    FontManager::load();
    mainFormManager = new FormManager();
    mainWindow = mainFormManager->getMainWindow();
    mainFormManager->addForm("main", new MainMenuForm());
    mainFormManager->setForm("main");
    mainFormManager->addForm("console", new ConsoleForm());
    mainFormManager->setForm("console");
//    consoleFormManager = new FormManager();
//    consoleWindow = consoleFormManager->getMainWindow();

    ConsoleManager::init(static_cast<ConsoleForm*>(mainFormManager->getForm("console")));
    console = ConsoleManager::get();
}

void Game::run()
{
    while(mainWindow->isOpen())
    {
        mainFormManager->update();
//        consoleFormManager->update();
    }
}
