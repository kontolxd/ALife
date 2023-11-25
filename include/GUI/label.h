#pragma once
#include "GUI/gui.h"
#include "ResourceManagers/fontmanager.h"
class Label : public GUI
{
private:
    sf::Text *textContent;
    sf::Color color;
public:
    Label(int x = 0, int y = 0, int w = 0, int h = 0, sf::Color color = sf::Color::White);
    Label(sf::Vector2f position, sf::Vector2f size, sf::Color color = sf::Color::White);

    void setFillColor(sf::Color);
    void setTextContent(std::string);
    void setGlobalPosition(sf::Vector2f pos);
    void setGlobalPosition(int w, int h);
    void setPosition(sf::Vector2f pos);
    void setPosition(int x, int y);

    sf::Color getFillColor();
    std::string getTextContent();
};
