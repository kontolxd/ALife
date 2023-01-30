#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "GUI/gui.h"
#include "GUI/button.h"
class Form
{
protected:
    //std::map<std::string, sf::Drawable> renderPoll;
    //TODO
    std::list<GUI*> GUIPoll;
    sf::RenderWindow *window;
    void mouseGUIInput();
    virtual void pollEvents() = 0;
    virtual void render() = 0;
public:
    sf::RenderWindow* getWindow();
    virtual void update() = 0;
};
