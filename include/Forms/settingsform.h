#pragma once
#include "Forms/form.h"
#include "Events/eventmanager.h"
#include "GUI/button.h"
#include "GUI/selector.h"
#include "GUI/spacer.h"

class SettingsForm : public Form
{
private:
    Layout *layout;
    Button *back_btn;
    Selector *language_slct;
    Selector *resolution_slct;

    sf::Text *languageSelect_text;
    sf::Text *resolution_text;

    EventManager *eventManager;
    sf::View GUIView;
    void mousePressInput(sf::Event event);
    void resize(sf::Event event);
    void initResolution();
    virtual void pollEvents() override;
    virtual void render() override;
public:
    SettingsForm();
    SettingsForm(sf::RenderWindow *window);
    virtual void update() override;
    virtual void init(sf::RenderWindow *window) override;
};
