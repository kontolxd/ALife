#include "GUI/button.h"

Button::Button(int x, int y, int w, int h, sf::Color color)
    : Button(sf::Vector2f(x, y), sf::Vector2f(w,h), color)
{}

Button::Button(sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    shell = new sf::RectangleShape();
    text = new sf::Text();
    clickable = true;

    this->globalPosition = position;
    this->size = size;
    this->fillColor = color;

    shell->setPosition(position);
    shell->setSize(size);
    shell->setFillColor(color);

    content["text"] = text;
    text->setPosition(position);
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
    text->setFont(*FontManager::get("FreeMono.otf"));
    text->setString(textContent);
    text->setFillColor(sf::Color::Red);
    text->setCharacterSize(24);
    text->setPosition(globalPosition.x + (size.x/2 - text->getLocalBounds().width/2),
                      globalPosition.y + size.y/2 - text->getCharacterSize());
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

    text->setPosition(globalPosition.x + (size.x/2 - text->getLocalBounds().width/2),
                      globalPosition.y + size.y/2 - text->getCharacterSize());
}

void Button::setGlobalPosition(int w, int h)
{
    setGlobalPosition(sf::Vector2f(w, h));
}

void Button::setPosition(sf::Vector2f pos)
{
    this->localPosition = pos;
    shell->setPosition(globalPosition + pos);

    text->setPosition(globalPosition.x + (size.x/2 - text->getLocalBounds().width/2),
                      globalPosition.y + size.y/2 - text->getCharacterSize());
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
