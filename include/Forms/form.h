#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "GUI/gui.h"
#include "GUI/button.h"
#include "GUI/layout.h"

class Form
{
protected:
    //std::map<std::string, sf::Drawable> renderPoll;
    //TODO
    std::list<GUI*> GUIPoll;
    sf::RenderWindow *window;
    void mouseGUIInput();
    void mouseClickElem(Button*);
    virtual void pollEvents() = 0;
    virtual void render() = 0;
public:
    sf::RenderWindow* getWindow();
    void setWindow(sf::RenderWindow *window);
    virtual void update() = 0;
    virtual void init(sf::RenderWindow *window) = 0;
};
