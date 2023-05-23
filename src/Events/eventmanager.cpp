#include "Events/eventmanager.h"

EventManager::EventManager(Form *parrent) : parrent(parrent)
{

}

EventManager::~EventManager()
{
    for(auto it : eventMap)
        delete it.second;
    for(auto it : keyboardEventMap)
        delete it.second;
}

void EventManager::handle(sf::Event &event)
{
    Event *ev;
    if(event.type == sf::Event::KeyPressed)
    {
        ev = keyboardEventMap[event.key.code];
        keyPressed = event.key.code;
        for(auto it : subscribers)
        {
            it->sendSubscribedKey(keyPressed);
        }
    }
    else
        ev = eventMap[event.type];
    if(ev != nullptr)
    {
        ev->setData(event);
        ev->active();
    }
    else
    {
        //Default events
        switch(event.type)
        {
        case sf::Event::Closed:
            if(parrent != nullptr)
                parrent->getWindow()->close();
            break;
        }
    }
}

void EventManager::addEvent(sf::Event::EventType type, Event *event)
{
    eventMap[type] = event;
    //eventMap[type]
}

void EventManager::addKeyboardEvent(Event *event, sf::Keyboard::Key key)
{
    keyboardEventMap[key] = event;
}

void EventManager::subscribe(GUI *subscriber)
{
    subscribers.push_back(subscriber);
}
