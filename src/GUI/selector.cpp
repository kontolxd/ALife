#include "GUI/selector.h"

Selector::Selector(int x, int y, int w, int h, sf::Color color)
    : Selector(sf::Vector2f(x, y), sf::Vector2f(w,h), color) {}

Selector::Selector(sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    isOpened = false;
    clickable = true;

    shell = new sf::RectangleShape();
    currentVariant = new sf::Text();

    this->globalPosition = position;
    this->size = size;
    this->fillColor = color;

    shell->setPosition(position);
    shell->setSize(size);
    shell->setFillColor(color);

    charSize = size.y - (size.y / 3);
    currentVariant->setFont(*FontManager::get("FreeMono.otf"));
    currentVariant->setFillColor(sf::Color::Black);
    //currentVariant->setPosition(0,0);
    currentVariant->setCharacterSize(charSize);

    content["currentVariant"] = currentVariant;

    clickDetector = new ClickForSelector();
    clickDetector->setN(0);
}

void Selector::testInit()
{
    addChild("test1");
    addChild("test2");
    addChild("test3");
    select(1);
}

void Selector::addChild(std::string text)
{
    SelectorChild *child = new SelectorChild(
        globalPosition.x,
        (globalPosition.y + size.y) * (variants.size()+1),
        size.x,
        size.y);
    child->setText(text);
    child->setClickDetector(clickDetector);
    child->setID(variants.size());
    child->setWindow(window);
    variants.push_back(child);
}

void Selector::select(int num)
{
    currentVariant->setString(variants[num]->getString());
}

void Selector::clicked()
{
    if(!isOpened)
    {
        int i = 0;
        for(; i < variants.size(); i++)
        {
            content["child" + std::to_string(i)] = variants[i];
        }
        defSizeY = size.y;
        size.y = size.y + (i * size.y);
    }
    else
    {
        for(int i = 0; i < variants.size(); i++)
        {
            bool ch = dynamic_cast<SelectorChild*>(content["child" + std::to_string(i)])->checkClicked(
                sf::Mouse::getPosition(*window).x,
                sf::Mouse::getPosition(*window).y
                );
            if(ch)
            {
                dynamic_cast<SelectorChild*>(content["child" + std::to_string(i)])->clicked();
                currentVariant->setString(variants[i]->getString());
            }
            content.erase("child" + std::to_string(i));
        }
        size.y = defSizeY;
    }
    isOpened = !isOpened;
}

void Selector::setParrent(Layout *parrent)
{
    this->parrent = parrent;
}

void Selector::setWindow(sf::RenderWindow *window)
{
    this->window = window;
}
