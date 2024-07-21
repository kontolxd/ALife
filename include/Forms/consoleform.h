#pragma once

#include <map>
#include <functional>
#include "Forms/form.h""
#include "GUI/layout.h"
#include "GUI/label.h"
#include "GUI/button.h"
#include "GUI/textedit.h"
#include "Events/eventmanager.h"

class ConsoleForm : public Form
{
private:
    int offsetY; // for command list
    std::list<Label*> pastCommands;
    std::string pastCommand;
    std::string *command;
    EventManager *eventManager;
    std::map<std::string, std::function<void()>*> commandsMap;
    void initCommands();
    void handleCommand(std::string command);
    virtual void pollEvents() override;
    virtual void render() override;
    ///GUI ELEMS///
    Layout *layout;
    TextEdit *text_textedit;
    Button *send_btn;
    ///EVENTS///
    void mousePressInput(sf::Event);
    void resize(sf::Event);
public:
    ConsoleForm();
    ConsoleForm(sf::RenderWindow *window);
    void sendError(std::string);
    void sendWarning(std::string);
    void sendMessage(std::string);
    virtual void update() override;
    virtual void init(sf::RenderWindow *window) override;

};
