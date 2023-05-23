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

    spacer = new Spacer(sf::Vector2f(50,50), sf::Vector2f(window->getSize().x, window->getSize().y));
    layout = new Layout(100,100,400,240, sf::Color::Transparent);
    newGame_btn = new Button(0, 0, 400, 100, sf::Color::Green);
    settings_btn = new Button(0, 0, 400, 100, sf::Color::Green);
    exit_btn = new Button(0, 0, 400, 100, sf::Color::Green);

    layout->addChild(newGame_btn);
    layout->addChild(settings_btn);
    layout->addChild(exit_btn);
    GUIPoll.push_back(layout);

    newGame_btn->setPosition(0,0);
    settings_btn->setPosition(0, 120);
    exit_btn->setPosition(0, 240);

    newGame_btn->setTextContent("New Game");
    settings_btn->setTextContent("Settings");
    exit_btn->setTextContent("Exit");

    spacer->setElem(layout);
    spacer->moveRight(150);

    newGame_btn->setCallback(*[](){std::cout<<"TEST!"<<std::endl;});


    //ted subscribe to eventmanager; event manager have subscribers
    ted = new TextEdit(0,0, 400,100);
    GUIPoll.push_back(ted);
    eventManager->subscribe(ted);
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
    window->setView(GUIView);
    for(auto it : GUIPoll)
        window->draw(*it);
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
