#pragma once
#include "Forms/form.h"
#include "Events/eventmanager.h"
#include "GUI/label.h"
#include "GUI/button.h"
#include "GUI/spacer.h"
#include "GUI/layout.h"

class MainMenuForm : public Form
{
private:
    //REMOVE IT!!!
    void test(sf::Event){std::cout<<"SEX"<<std::endl;}
    //REMOVE IT!!!!
    void sex(sf::Event){std::cout<<"ASSWECAN!"<<std::endl;}
    Spacer *spacer;
    sf::RectangleShape *rect;
    sf::RectangleShape *rect2;
    sf::RectangleShape *rect3;
    Label *label;
    Button *btn;
    Layout *layout;

    sf::View WorldView;
    sf::View GUIView;
    virtual void render() override;
    virtual void pollEvents() override;

    EventManager *eventManager;
private:
    ///EVENTS///
    void mousePressInput(sf::Event);
    void resize(sf::Event);
public:
    MainMenuForm(sf::RenderWindow *window);
    virtual void update() override;
};
