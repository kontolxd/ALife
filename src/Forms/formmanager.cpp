#include "Forms/formmanager.h"

FormManager::FormManager()
{
    width = 1000;
    height = 800;
    title = "ALife";
    mainWindow = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Titlebar | sf::Style::Close);
//    mainMenuForm = new MainMenuForm(mainWindow);
//    currentForm = mainMenuForm;
}

void FormManager::update()
{
    currentForm->update();
}

void FormManager::addForm(std::string name, Form *form)
{
    formsMap[name] = form;
}

void FormManager::setForm(std::string name)
{
    currentForm = formsMap[name];
}

sf::RenderWindow* FormManager::getMainWindow()
{
    return mainWindow;
}

