#pragma once
#include <bitset>
#include "GUI/gui.h"

class Spacer
{
private:
    GUI *elem;
    sf::Vector2f windowSize;
    sf::Vector2f pos;

    void update();
public:
    Spacer(sf::Vector2f pos = sf::Vector2f(0,0), sf::Vector2f windowSize = sf::Vector2f(0,0));

    void toBot();
    void toTop();
    void toLeft();
    void toRight();

    void setElem(GUI *elem);
    void setPos(sf::Vector2f pos);

    void moveDown(int percent);
    void moveUp(int percent);
    void moveLeft(int percent);
    void moveRight(int percent);

    void resize(int w, int h);

    GUI *getElem();
    sf::Vector2f getPos();
};
