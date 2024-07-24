#include "Forms/form.h"

Form::Form()
{
    requestFlag = false;
    requestedFormName = "";
}

sf::RenderWindow* Form::getWindow()
{
    return window;
}

void Form::mouseGUIInput()
{
    //REWRITE THIS FUCKING SHITCODE!!!!!!!!!!!
    sf::Vector2i click;
    click.x = sf::Mouse::getPosition(*window).x;
    click.y = sf::Mouse::getPosition(*window).y;
    for(auto elem : GUIPoll)
    {
        sf::Vector2f pos = elem->getPosition() + elem->getGlobalPosition();
        sf::Vector2f size = elem->getSize();
        if(click.x > pos.x && click.x < pos.x+size.x && click.y > pos.y && click.y < pos.y+size.y)
        {
            //if our element is container, then we check his childs on clickable
            if(elem->isContainer())
            {
                auto container = dynamic_cast<Layout*>(elem)->getChilds();
                for(auto innerElem : *container)
                {
                    if(innerElem->isClickable())
                    {
                        pos = innerElem->getGlobalPosition();
                        size = innerElem->getSize();
                        if(click.x > pos.x && click.x < pos.x+size.x && click.y > pos.y && click.y < pos.y+size.y)
                        {
                            dynamic_cast<IClickable*>(innerElem)->clicked();
                        }
                    }
                }
            }
            if(elem->isClickable())
            {
                dynamic_cast<IClickable*>(elem)->clicked();
            }
        }
    }
}

void Form::setWindow(sf::RenderWindow *window)
{
    this->window = window;
}

bool Form::checkRequest()
{
    return requestFlag;
}

void Form::requestForm(std::string name)
{
    requestFlag = true;
    requestedFormName = name;
}

void Form::completeRequest()
{
    requestFlag = false;
}

std::string Form::getRequestedName()
{
    return requestedFormName;
}
