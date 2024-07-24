#pragma once
#include "Forms/form.h"
#include "Events/eventmanager.h"
#include "GUI/button.h"
class SettingsForm : public Form
{
private:
    Layout *layout;
    Button *back_btn;

    EventManager *eventManager;
    sf::View GUIView;
    void mousePressInput(sf::Event event);
    void resize(sf::Event event);
    virtual void pollEvents() override;
    virtual void render() override;
public:
    SettingsForm();
    SettingsForm(sf::RenderWindow *window);
    virtual void update() override;
    virtual void init(sf::RenderWindow *window) override;
};
