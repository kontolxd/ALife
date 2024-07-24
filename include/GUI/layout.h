#pragma once
#include <iostream>
#include <list>
#include "GUI/gui.h"

class Layout : public GUI
{
private:
    std::list<GUI*> childs;
    sf::Color fillColor;
    void update();
public:
    Layout(int x = 0, int y = 0, int w = 0, int h = 0, sf::Color color = sf::Color::White);
    Layout(sf::Vector2f position, sf::Vector2f size, sf::Color = sf::Color::White);

    virtual void setGlobalPosition(sf::Vector2f) override;
    virtual void setGlobalPosition(int x, int y) override;
    virtual void setSize(sf::Vector2f) override;
    virtual void setSize(int w, int h) override;

    void addChild(GUI*);
    void addChild(GUI*, sf::Vector2f position);
    void removeChild(GUI*);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    std::list<GUI*> *getChilds();
};
