#include "Forms/mainmenuform.h"

MainMenuForm::MainMenuForm()
{

}

MainMenuForm::MainMenuForm(sf::RenderWindow *window)
{
    init(window);
}

void MainMenuForm::init(sf::RenderWindow *window)
{
    eventManager = new EventManager(this);
    this->window = window;

    Event *mousePressEvenet = new Event();
    Event *resizeEvent = new Event();

    mousePressEvenet->setCallback(&MainMenuForm::mousePressInput, this);
    resizeEvent->setCallback(&MainMenuForm::resize, this);

    eventManager->addEvent(sf::Event::MouseButtonPressed, mousePressEvenet);
    eventManager->addEvent(sf::Event::Resized, resizeEvent);

    spacer = new Spacer(sf::Vector2f(50,50), sf::Vector2f(window->getSize().x, window->getSize().y));
    layout = new Layout(100,100,400,500, sf::Color::Transparent);
    newGame_btn = new Button(0, 0, 400, 100, sf::Color::Green);
    settings_btn = new Button(0, 0, 400, 100, sf::Color::Green);
    exit_btn = new Button(0, 0, 400, 100, sf::Color::Green);
    loadGame_btn = new Button(0,0,400,100,sf::Color::Green);

    layout->addChild(newGame_btn);
    layout->addChild(settings_btn);
    layout->addChild(exit_btn);
    layout->addChild(loadGame_btn);
    GUIPoll.push_back(layout);

    newGame_btn->setPosition(0,0);
    loadGame_btn->setPosition(0, 120);
    settings_btn->setPosition(0, 240);
    exit_btn->setPosition(0, 360);


    newGame_btn->setTextContent("New Game");
    settings_btn->setTextContent("Settings");
    loadGame_btn->setTextContent("Load game");
    exit_btn->setTextContent("Exit");

    spacer->setElem(layout);
    spacer->moveRight(150);

    newGame_btn->setCallback([](){std::cout<<"TEST!"<<std::endl;});
    loadGame_btn->setCallback([](){std::cout<<"TEST!"<<std::endl;});
    settings_btn->setCallback(new std::function<void()>([this](){
                    this->requestForm("settings");
    }));
    exit_btn->setCallback(new std::function<void()>([this](){
            this->window->close();
    }));
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
