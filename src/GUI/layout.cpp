#include "GUI/layout.h"

Layout::Layout(int x, int y, int w, int h, sf::Color color)
    : Layout(sf::Vector2f(x, y), sf::Vector2f(w, h), color)
{
}

Layout::Layout(sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    container = true;
    parrent = nullptr;
    shell = new sf::RectangleShape();

    this->globalPosition = position;
    this->size = size;
    this->fillColor = color;

    shell->setPosition(position);
    shell->setSize(size);
    shell->setFillColor(color);
}

///SETTERS///

void Layout::setGlobalPosition(sf::Vector2f pos)
{
    this->globalPosition = pos;
    update();
}

void Layout::setGlobalPosition(int w, int h)
{
    setGlobalPosition(sf::Vector2f(w, h));
}

void Layout::setSize(sf::Vector2f size)
{
    this->size = size;
    shell->setSize(size);
}

void Layout::setSize(int w, int h)
{
    setSize(sf::Vector2f(w, h));
}

///OTHER///

void Layout::update()
{
    shell->setPosition(globalPosition);
    for(auto elem : childs)
    {
        int x = elem->getPosition().x;
        int y = elem->getPosition().y;
        elem->setGlobalPosition(x + globalPosition.x, y + globalPosition.y);
    }
}

void Layout::addChild(GUI *elem)
{
    elem->setGlobalPosition(0,0);
    elem->setParrent(this);
    childs.push_back(elem);
    update();
}

void Layout::addChild(GUI *elem, sf::Vector2f position)
{
    elem->setGlobalPosition(position);
    elem->setPosition(position);
    elem->setParrent(this);
    childs.push_back(elem);
    update();
}

void Layout::removeChild(GUI *elem)
{
    childs.remove(elem);
}

void Layout::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*shell);
    for(auto elem : childs)
    {
        target.draw(*elem, states);
    }
}

std::list<GUI*> *Layout::getChilds()
{
    return &childs;
}
