#include "GUI/selectorchild.h"

SelectorChild::SelectorChild(int x, int y, int w, int h, sf::Color color)
    : SelectorChild(sf::Vector2f(x, y), sf::Vector2f(w,h), color){}

SelectorChild::SelectorChild(sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    clickable = true;

    shell = new sf::RectangleShape();
    text = new sf::Text();

    this->globalPosition = position;
    this->size = size;
    this->fillColor = color;

    shell->setPosition(position);
    shell->setSize(size);
    shell->setFillColor(color);

    charSize = size.y - (size.y / 3);
    text->setFont(*FontManager::get("FreeMono.otf"));
    text->setFillColor(sf::Color::Black);
    text->setPosition(position);
    text->setCharacterSize(charSize);

    content["text"] = text;
}

std::string SelectorChild::getString()
{
    return text->getString();
}

bool SelectorChild::checkClicked(int clickX, int clickY)
{
    sf::Vector2f pos = globalPosition;
    //std::cout<<std::endl;
    if(clickX > pos.x && clickX < pos.x+size.x && clickY > pos.y && clickY < pos.y+size.y)
    {
        return true;
    }
    return false;
}

void SelectorChild::clicked()
{
    clickDetector->setN(id);
}

void SelectorChild::setText(std::string text)
{
    this->text->setString(text);
}

void SelectorChild::setClickDetector(ClickForSelector *clickDetector)
{
    this->clickDetector = clickDetector;
}

void SelectorChild::setID(int id)
{
    this->id = id;
}

void SelectorChild::setWindow(sf::RenderWindow *window)
{
    this->window = window;
}

void SelectorChild::setPosition(int x, int y)
{
    GUI::setPosition(sf::Vector2f(x, y));
}

void SelectorChild::setPosition(sf::Vector2f pos)
{
    GUI::setPosition(pos);
}
