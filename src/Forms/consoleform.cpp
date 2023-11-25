#include "Forms/consoleform.h"

ConsoleForm::ConsoleForm()
{

}

ConsoleForm::ConsoleForm(sf::RenderWindow *window)
{
    init(window);
}

void ConsoleForm::init(sf::RenderWindow *window)
{
    eventManager = new EventManager(this);
    this->window = window;

    Event *mousePressEvenet = new Event();
    Event *resizeEvent = new Event();

    mousePressEvenet->setCallback(&ConsoleForm::mousePressInput, this);
    resizeEvent->setCallback(&ConsoleForm::resize, this);

    eventManager->addEvent(sf::Event::MouseButtonPressed, mousePressEvenet);
    eventManager->addEvent(sf::Event::Resized, resizeEvent);

    layout = new Layout(0, 0, window->getSize().x, window->getSize().y, sf::Color::Transparent);
    text_textedit = new TextEdit(0, 0, window->getSize().x - 30, 30, sf::Color::White);
    send_btn = new Button();

    layout->addChild(text_textedit);
    layout->addChild(send_btn);
    layout->addChild(text_textedit);
    GUIPoll.push_back(layout);

    eventManager->subscribe(text_textedit);

    send_btn->setPosition(window->getSize().x - 30, 0);
    send_btn->setSize(30,30);
    send_btn->setFillColor(sf::Color::Red);

    text_textedit->setSendable(true);
    command = new std::string;
    text_textedit->strSubscribe(command);
    pastCommand = "";
    offsetY = 30;
}

void ConsoleForm::render()
{
    //REWRITE!!!!!
    window->clear(sf::Color::Black);
    //window->setView(GUIView);
    for(auto it : GUIPoll)
        window->draw(*it);
    window->display();
}

void ConsoleForm::update()
{
    pollEvents();
    if(*command != pastCommand)
    {
        pastCommands.push_back(new Label(0, offsetY, window->getSize().x, 30, sf::Color::Transparent));
        pastCommands.back()->setTextContent(*command);
        GUIPoll.push_back(pastCommands.back());
        pastCommand = *command;
        offsetY += 30;
    }
    render();
}

void ConsoleForm::pollEvents()
{
    sf::Event event;
    while(window->pollEvent(event))
    {
        eventManager->handle(event);
    }
}

///EVENTS///
void ConsoleForm::mousePressInput(sf::Event event)
{
    mouseGUIInput();
}

void ConsoleForm::resize(sf::Event event)
{
//    GUIView.setSize(event.size.width, event.size.height);
//    GUIView.setCenter(sf::Vector2f(event.size.width/2, event.size.height/2));
}
