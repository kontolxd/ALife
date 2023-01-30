#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>
#include "Events/data.h"

class Event
{
private:
    //Only keyboard event
    sf::Keyboard::Key activeKey;
    sf::Event data;
    std::function<void(sf::Event)> callback;
public:
    Event();
    void active();
    void setCallback(std::function<void(sf::Event)>&);
    void setData(sf::Event data);
    void setKey(sf::Keyboard::Key);
    sf::Event getData();
    sf::Keyboard::Key getKey();
public:
    template<class T>
    void setCallback(void(T::*func)(sf::Event), T *instance)
    {
        auto tmp = std::bind(func, instance, std::placeholders::_1);
        callback = tmp;
    }
};


