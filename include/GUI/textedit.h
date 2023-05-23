#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "GUI/gui.h"
#include "ResourceManagers/fontmanager.h"

class TextEdit : public GUI
{
private:
    std::string textEntered;
    sf::Color fillColor;
    sf::Text *text;
public:
    TextEdit(int x = 0, int y = 0, int w = 0, int h = 0, sf::Color color = sf::Color::White);
    TextEdit(sf::Vector2f position, sf::Vector2f size, sf::Color color);

    void send();

    virtual void sendSubscribedKey(sf::Keyboard::Key) override;
};
