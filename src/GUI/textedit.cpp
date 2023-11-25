#include "GUI/textedit.h"

TextEdit::TextEdit(int x, int y, int w, int h, sf::Color color)
    : TextEdit(sf::Vector2f(x, y), sf::Vector2f(w,h), color){}

TextEdit::TextEdit(sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    shell = new sf::RectangleShape();
    text = new sf::Text();

    this->globalPosition = position;
    this->size = size;
    this->fillColor = color;

    shell->setPosition(position);
    shell->setSize(size);
    shell->setFillColor(color);

    text->setFillColor(sf::Color::Red);
    text->setCharacterSize(size.y - (size.y / 3));
    text->setFont(*FontManager::get("FreeMono.otf"));
    text->setPosition(0,0);

    content["text"] = text;

    canSend = false;
}

void TextEdit::sendSubscribedKey(sf::Keyboard::Key key)
{
    GUI::sendSubscribedKey(key);
    if(key == 59)
        textEntered.pop_back();
    else if (key == sf::Keyboard::Enter)
    {
        if(canSend)
        {
            send(textEntered);
            textEntered.clear();
        }
    }
    else
        textEntered.push_back(key + 'a');
    text->setString(textEntered);
}

void TextEdit::setSendable(bool c)
{
    canSend = c;
}

void TextEdit::send(std::string text)
{
    for(auto it : str_subscribers)
    {
        *it = text;
    }
}

void TextEdit::strSubscribe(std::string *subscriber)
{
    str_subscribers.push_back(subscriber);
}
