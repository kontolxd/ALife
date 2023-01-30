#pragma once
#include <SFML/Graphics.hpp>
#include "Forms/mainmenuform.h"

class FormManager
{
private:
    Form *currentForm;
    MainMenuForm *mainMenuForm;
private:
    int width, height;
    std::string title;
    sf::RenderWindow *mainWindow;
public:
    FormManager();
    void update();
    sf::RenderWindow* getMainWindow();
};
