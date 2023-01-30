#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>

class GUI : public sf::Drawable
{
protected:
    std::unordered_map<std::string, sf::Drawable*> content;
    sf::Vector2f globalPosition;
    sf::Vector2f localPosition;
    sf::Vector2f size;
    sf::RectangleShape *shell;
    GUI *parrent;
    bool clickable;
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    virtual void setGlobalPosition(sf::Vector2f);
    virtual void setGlobalPosition(int x, int y);
    virtual void setPosition(sf::Vector2f);
    virtual void setPosition(int x, int y);
    virtual void setSize(sf::Vector2f);
    virtual void setSize(int w, int h);
    virtual void setParrent(GUI*);

    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    sf::Vector2f getGlobalPosition();

    bool isClickable();
};
