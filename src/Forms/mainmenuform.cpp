#include "Forms/mainmenuform.h"

MainMenuForm::MainMenuForm(sf::RenderWindow *window)
{
    eventManager = new EventManager(this);
    this->window = window;

    Event *mousePressEvenet = new Event();
    Event *resizeEvent = new Event();

    mousePressEvenet->setCallback(&MainMenuForm::mousePressInput, this);
    resizeEvent->setCallback(&MainMenuForm::resize, this);

    eventManager->addEvent(sf::Event::MouseButtonPressed, mousePressEvenet);
    eventManager->addEvent(sf::Event::Resized, resizeEvent);

    //REMOVE IT!!!
    Event *ev = new Event();
    Event *ev2 = new Event();
//    ev->setCallback(&MainMenuForm::test, this);
//    eventManager->addKeyboardEvent(ev, sf::Keyboard::S);

    rect = new sf::RectangleShape();
    rect2 = new sf::RectangleShape();
    rect3 = new sf::RectangleShape();
    rect->setPosition(100,100); //player
    rect->setSize(sf::Vector2f(100,100));
    rect->setFillColor(sf::Color::Blue);
    rect2->setPosition(400,400); //object
    rect2->setSize(sf::Vector2f(100,100));
    rect2->setFillColor(sf::Color::Red);
    rect3->setPosition(0,800); //GUI
    rect3->setSize(sf::Vector2f(800,100));
    rect3->setFillColor(sf::Color::Green);

    layout = new Layout(sf::Vector2f(200,200), sf::Vector2f(300,300));
    spacer = new Spacer();
    label = new Label(100,100,100,100,sf::Color::Red);
    btn = new Button(100,400,100,100,sf::Color::Green);
    GUIPoll.push_back(btn);
    layout->addChild(btn);
    layout->addChild(label);
    btn->setPosition(10,0);
    label->setPosition(100,100);
}

void MainMenuForm::pollEvents()
{
    sf::Event event;
    while(window->pollEvent(event))
    {
        eventManager->handle(event);
    }
}

void MainMenuForm::render()
{
    //REWRITE!!!!!
    window->clear(sf::Color::Black);
    rect->move(0,0.01f);
    WorldView.setCenter(rect->getPosition());
    window->setView(WorldView);
    window->draw(*rect);
    window->draw(*rect2);
    window->setView(GUIView);
    window->draw(*layout);
    window->display();
}

void MainMenuForm::update()
{
    pollEvents();
    render();
}

///EVENTS///
void MainMenuForm::mousePressInput(sf::Event event)
{
    mouseGUIInput();
}

void MainMenuForm::resize(sf::Event event)
{
    GUIView.setSize(event.size.width, event.size.height);
    GUIView.setCenter(sf::Vector2f(event.size.width/2, event.size.height/2));
}
