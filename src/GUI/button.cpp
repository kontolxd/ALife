#include "GUI/button.h"

Button::Button(int x, int y, int w, int h, sf::Color color)
    : Button(sf::Vector2f(x, y), sf::Vector2f(w,h), color)
{}

Button::Button(sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    shell = new sf::RectangleShape();
    clickable = true;

    this->globalPosition = position;
    this->size = size;
    this->fillColor = color;

    shell->setPosition(position);
    shell->setSize(size);
    shell->setFillColor(color);
}

void Button::clicked()
{
    callback();
}

///SETTERS///

void Button::setFillColor(sf::Color color)
{
    shell->setFillColor(color);
    fillColor = color;
}

void Button::setTextContent(std::string content)
{
    //TODO!
    textContent = content;
}

void Button::setCallback(std::function<void()>)
{
    //TODO!
}

void Button::setCallback(void (*callback)())
{
    this->callback = callback;
}

void Button::setGlobalPosition(sf::Vector2f pos)
{
    this->globalPosition = pos;
    shell->setPosition(pos);
}

void Button::setGlobalPosition(int w, int h)
{
    setGlobalPosition(sf::Vector2f(w, h));
}

void Button::setPosition(sf::Vector2f pos)
{
    this->localPosition = pos;
    shell->setPosition(globalPosition + pos);
}

void Button::setPosition(int x, int y)
{
    setPosition(sf::Vector2f(x, y));
}

void Button::setSize(sf::Vector2f size)
{
    shell->setSize(size);
    this->size = size;
}

void Button::setSize(int w, int h)
{
    shell->setSize(sf::Vector2f(w, h));
    this->size = sf::Vector2f(w, h);
}

///GETTERS

sf::Color Button::getFillColor()
{
    return fillColor;
}

std::string Button::getTextContent()
{
    return textContent;
}
