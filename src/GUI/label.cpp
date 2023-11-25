#include "GUI/label.h"

Label::Label(int x, int y, int w, int h, sf::Color color)
    : Label(sf::Vector2f(x, y), sf::Vector2f(w, h), color)
{}

Label::Label(sf::Vector2f position, sf::Vector2f size, sf::Color color) : color(color)
{
    shell = new sf::RectangleShape();
    textContent = new sf::Text();
    clickable = false;

    this->globalPosition.x = position.x;
    this->globalPosition.y = position.y;
    this->size.x = size.x;
    this->size.y = size.y;

    shell->setPosition(this->globalPosition);
    shell->setSize(this->size);
    shell->setFillColor(color);

    content["text"] = textContent;
    textContent->setPosition(position);
}

///SETERS///

void Label::setFillColor(sf::Color color)
{
    this->color = color;
}

void Label::setTextContent(std::string content)
{
    //TODO!
    //textContent = content;
    textContent->setFont(*FontManager::get("FreeMono.otf"));
    textContent->setString(content);
    textContent->setFillColor(sf::Color::Red);
    textContent->setCharacterSize(24);
    textContent->setPosition(globalPosition.x + (size.x/2 - textContent->getLocalBounds().width/2),
                      globalPosition.y + size.y/2 - textContent->getCharacterSize());
}

void Label::setGlobalPosition(sf::Vector2f pos)
{
    this->globalPosition = pos;
    shell->setPosition(pos);

    textContent->setPosition(globalPosition.x + (size.x/2 - textContent->getLocalBounds().width/2),
                      globalPosition.y + size.y/2 - textContent->getCharacterSize());
}

void Label::setGlobalPosition(int w, int h)
{
    setGlobalPosition(sf::Vector2f(w, h));
}

void Label::setPosition(sf::Vector2f pos)
{
    this->localPosition = pos;
    shell->setPosition(globalPosition + pos);

    textContent->setPosition(globalPosition.x + (size.x/2 - textContent->getLocalBounds().width/2),
                      globalPosition.y + size.y/2 - textContent->getCharacterSize());
}

void Label::setPosition(int x, int y)
{
    setPosition(sf::Vector2f(x, y));
}

///GETTERS///

sf::Color Label::getFillColor()
{
    return color;
}

std::string Label::getTextContent()
{
    return textContent->getString();
}
