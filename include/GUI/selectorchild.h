#pragma once
#include "GUI/gui.h"
#include "GUI/interfaces/iclickable.h"
#include "ResourceManagers/fontmanager.h"

#include "GUI/crutches/clickforselector.h"

#include <stdio.h>
class SelectorChild : public GUI, public IClickable
{
private:
    sf::Text *text;
    sf::Color fillColor;
    int charSize;
    ClickForSelector *clickDetector;
    int id;
    sf::RenderWindow *window;
public:
    SelectorChild(int x = 0, int y = 0, int w = 0, int h = 0, sf::Color color = sf::Color::White);
    SelectorChild(sf::Vector2f position, sf::Vector2f size, sf::Color color);

    void clicked();
    bool checkClicked(int clickX, int clickY);
    void setText(std::string);
    void setClickDetector(ClickForSelector*);
    void setID(int n);
    void setWindow(sf::RenderWindow *window);
    std::string getString();

    virtual void setPosition(int x, int y) override;
    virtual void setPosition(sf::Vector2f position) override;
};
