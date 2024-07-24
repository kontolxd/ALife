#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "GUI/gui.h"
#include "GUI/button.h"
#include "GUI/layout.h"

class Form
{
private:
    //Request for swap forms
    bool requestFlag;
    std::string requestedFormName;
protected:
    //std::map<std::string, sf::Drawable> renderPoll;
    //TODO

    Form();

    std::list<GUI*> GUIPoll;
    sf::RenderWindow *window;
    void requestForm(std::string name);
    void mouseGUIInput();
    void mouseClickElem(Button*);
    virtual void pollEvents() = 0;
    virtual void render() = 0;
public:
    //Request methods
    bool checkRequest();
    void completeRequest();
    std::string getRequestedName();

    //Other
    sf::RenderWindow* getWindow();
    void setWindow(sf::RenderWindow *window);
    virtual void update() = 0;
    virtual void init(sf::RenderWindow *window) = 0;
};
