#pragma once
#include <vector>
#include "GUI/gui.h"
#include "GUI/selectorchild.h"
#include "GUI/interfaces/iclickable.h"
#include "GUI/crutches/clickforselector.h"
#include "GUI/layout.h"
#include "ResourceManagers/fontmanager.h"

//мега костыльная х*уйня

class Selector : public GUI, public IClickable
{
private:
    Layout *parrent;
    sf::Color fillColor;
    sf::Text *currentVariant;
    std::vector<SelectorChild*> variants;
    void select(int num);
    int charSize;
    int defSizeY;
    bool isOpened;
    ClickForSelector *clickDetector;
    sf::RenderWindow *window;
public:
    void testInit();

    Selector(int x = 0, int y = 0, int w = 0, int h = 0, sf::Color color = sf::Color::White);
    Selector(sf::Vector2f position, sf::Vector2f size, sf::Color = sf::Color::White);

    void addChild(std::string text);
    void setParrent(Layout*);
    void setWindow(sf::RenderWindow *window);

    virtual void clicked() override;
};
