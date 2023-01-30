#include "GUI/label.h"

Label::Label(int x, int y, int w, int h, sf::Color color)
    : Label(sf::Vector2f(x, y), sf::Vector2f(w, h), color)
{}

Label::Label(sf::Vector2f position, sf::Vector2f size, sf::Color color) : color(color)
{
    shell = new sf::RectangleShape();
    clickable = false;

    this->globalPosition.x = position.x;
    this->globalPosition.y = position.y;
    this->size.x = size.x;
    this->size.y = size.y;

    shell->setPosition(this->globalPosition);
    shell->setSize(this->size);
    shell->setFillColor(color);
}

///SETERS///

void Label::setFillColor(sf::Color color)
{
    this->color = color;
}

void Label::setTextContent(std::string content)
{
    this->textContent.setString(content);
}

///GETTERS///

sf::Color Label::getFillColor()
{
    return color;
}

std::string Label::getTextContent()
{
    return textContent.getString();
}
