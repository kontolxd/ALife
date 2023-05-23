#pragma once
#include "Forms/form.h"
#include "Events/eventmanager.h"
#include "GUI/textedit.h""
#include "GUI/button.h"
#include "GUI/spacer.h"
#include "GUI/layout.h"

class MainMenuForm : public Form
{
private:
    //DELETE IT!!!
    TextEdit *ted;
    //

    Spacer *spacer;
    sf::RectangleShape *rect;
    sf::RectangleShape *rect2;
    sf::RectangleShape *rect3;

    Layout *layout;
    Button *newGame_btn;
    Button *settings_btn;
    Button *exit_btn;

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
