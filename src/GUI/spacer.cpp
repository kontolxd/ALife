#include "GUI/spacer.h"

Spacer::Spacer(sf::Vector2f pos, sf::Vector2f windowSize) : pos(pos), windowSize(windowSize)
{

}

void Spacer::update()
{
    float x = pos.x / 100.0f;
    float y = pos.y / 100.0f;
    x = windowSize.x*x - elem->getSize().x/2;
    y = windowSize.y*y - elem->getSize().y/2;
    elem->setGlobalPosition(x, y);
}

///MOVE///

void Spacer::toBot()
{
    float y = windowSize.y - elem->getSize().y/2;
    pos.y = (y*100.0f)/windowSize.y;
    update();
}

void Spacer::toTop()
{
    float y = 0 + elem->getSize().y/2;
    pos.y = (y*100.f)/windowSize.y;
    update();
}

void Spacer::toLeft()
{
    float x = 0 + elem->getSize().y/2;
    pos.x = (x*100.0f)/windowSize.x;
    update();
}

void Spacer::toRight()
{
    float x = windowSize.x - elem->getSize().x/2;
    pos.x = (x*100.0f)/windowSize.x;
    update();
}

void Spacer::moveDown(int percent)
{
    pos.y += percent;
}

void Spacer::moveUp(int percent)
{
    pos.y -= percent;
}

void Spacer::moveLeft(int percent)
{
    pos.x -= percent;
}

void Spacer::moveRight(int percent)
{
    pos.y += percent;
}

///SETTERS///

void Spacer::setElem(GUI *elem)
{
    this->elem = elem;
    update();
}

void Spacer::setPos(sf::Vector2f pos)
{
    this->pos = pos;
    update();
}

///GETTERS///

GUI* Spacer::getElem()
{
    return elem;
}

sf::Vector2f Spacer::getPos()
{
    return pos;
}

///OTHER///

void Spacer::resize(int w, int h)
{
    windowSize.x = w;
    windowSize.y = h;
    update();
}
