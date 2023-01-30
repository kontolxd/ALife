#pragma once
#include <unordered_map>
#include "Events/event.h"
#include "Forms/form.h"

using EventMap = std::unordered_map<sf::Event::EventType, Event*>;
using KeyboardEventMap = std::unordered_map<sf::Keyboard::Key, Event*>;
//pollEvents передает контроль данному классу

class EventManager
{
private:
     EventMap eventMap;
     KeyboardEventMap keyboardEventMap;
     Form *parrent;
public:
    EventManager(Form *parrent = nullptr);
    ~EventManager();
    void handle(sf::Event &event);
    void addEvent(sf::Event::EventType, Event*);
    void addKeyboardEvent(Event*, sf::Keyboard::Key);
    //void removeEvent(sf::Event::EventType);
    void editEvent();
};
