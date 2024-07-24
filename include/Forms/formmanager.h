#pragma once
#include <SFML/Graphics.hpp>

#include "Forms/mainmenuform.h"
#include "Forms/consoleform.h"

class FormManager
{
private:
    std::unordered_map<std::string, Form*> formsMap;
    Form *currentForm;
    //MainMenuForm *mainMenuForm;
private:
    int width, height;
    std::string title;
    sf::RenderWindow *mainWindow;
public:
    FormManager();

    void update();
    void addForm(std::string name, Form *form);
    void setForm(std::string name);
    Form* getForm(std::string name);
    Form* getCurrentForm();

    sf::RenderWindow* getMainWindow();
};
