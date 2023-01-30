#include "Forms/formmanager.h"

FormManager::FormManager()
{
    width = 1000;
    height = 800;
    title = "ALife";
    mainWindow = new sf::RenderWindow(sf::VideoMode(width, height), title);
    mainMenuForm = new MainMenuForm(mainWindow);
    currentForm = mainMenuForm;
}

void FormManager::update()
{
    currentForm->update();
}

sf::RenderWindow* FormManager::getMainWindow()
{
    return mainWindow;
}
