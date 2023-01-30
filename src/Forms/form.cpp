#include "Forms/form.h"

sf::RenderWindow* Form::getWindow()
{
    return window;
}

void Form::mouseGUIInput()
{
    sf::Vector2i click;
    click.x = sf::Mouse::getPosition(*window).x;
    click.y = sf::Mouse::getPosition(*window).y;
    for(auto elem : GUIPoll)
    {
        if(elem->isClickable())
        {
            sf::Vector2f pos = elem->getPosition() + elem->getGlobalPosition();
            sf::Vector2f size = elem->getSize();
            if(click.x > pos.x && click.x < pos.x+size.x && click.y > pos.y && click.y < pos.y+size.y)
            {
                dynamic_cast<Button*>(elem)->clicked();
            }
        }
    }
}
