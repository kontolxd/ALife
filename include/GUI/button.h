#pragma once
#include <functional>
#include <iostream>
#include "ResourceManagers/fontmanager.h"
#include "GUI/gui.h"

class Button : public GUI
{
private:
    sf::Color fillColor;
    sf::Text *text;
    //sf::RectangleShape *shell;
    std::string textContent;
    std::function<void()> callback;
    void nothing(){};
public:
    Button(int x = 0, int y = 0, int w = 0, int h = 0, sf::Color color = sf::Color::White);
    Button(sf::Vector2f position, sf::Vector2f size, sf::Color = sf::Color::White);

    void clicked();

    void setFillColor(sf::Color);
    void setTextContent(std::string);
    void setCallback(std::function<void()>);
    void setCallback(void (*callback)());
    virtual void setGlobalPosition(sf::Vector2f pos) override;
    virtual void setGlobalPosition(int x, int y) override;
    virtual void setPosition(sf::Vector2f pos) override;
    virtual void setPosition(int x, int y) override;
    virtual void setSize(sf::Vector2f size) override;
    virtual void setSize(int w, int h) override;

    sf::Color getFillColor();
    std::string getTextContent();

    //virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
