#include "Events/event.h"

Event::Event()
{

}

void Event::active()
{
    callback(data);
}

void Event::setCallback(std::function<void(sf::Event)> &func)
{
    callback = func;
}

void Event::setData(sf::Event data)
{
    this->data = data;
}

void Event::setKey(sf::Keyboard::Key key)
{
    this->activeKey = key;
}

sf::Event Event::getData()
{
    return data;
}

sf::Keyboard::Key Event::getKey()
{
    return activeKey;
}
