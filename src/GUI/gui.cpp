#include "GUI/gui.h"


bool GUI::isClickable()
{
    return clickable;
}

bool GUI::isContainer()
{
    return container;
}

void GUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*shell);
    for(auto it : content)
    {
        target.draw(*it.second);
    }
}

void GUI::sendSubscribedKey(sf::Keyboard::Key key)
{
    pressedKey = key;
}

///SETTERS///
void GUI::setGlobalPosition(sf::Vector2f position)
{
    this->globalPosition = position;
    shell->setPosition(position);
}

void GUI::setGlobalPosition(int x, int y)
{
    setGlobalPosition(sf::Vector2f(x, y));
}

void GUI::setPosition(sf::Vector2f position)
{
    this->localPosition = position;
    shell->setPosition(globalPosition + localPosition);
    setGlobalPosition(globalPosition + localPosition);
}

void GUI::setPosition(int x, int y)
{
    setPosition(sf::Vector2f(x,y));
}

void GUI::setSize(sf::Vector2f size)
{
    this->size = size;
}

void GUI::setSize(int w, int h)
{
    this->size = sf::Vector2f(w, h);
}

void GUI::setParrent(GUI *parrent)
{
    this->parrent = parrent;
}

///GETTERS///
sf::Vector2f GUI::getPosition()
{
    return localPosition;
}

sf::Vector2f GUI::getSize()
{
    return size;
}

sf::Vector2f GUI::getGlobalPosition()
{
    return globalPosition;
}
