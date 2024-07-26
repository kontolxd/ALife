#include "Forms/settingsform.h"

SettingsForm::SettingsForm() {}

SettingsForm::SettingsForm(sf::RenderWindow *window)
{
    init(window);
}

void SettingsForm::init(sf::RenderWindow *window)
{
    eventManager = new EventManager(this);
    this->window = window;

    Event *mousePressEvenet = new Event();
    Event *resizeEvent = new Event();

    mousePressEvenet->setCallback(&SettingsForm::mousePressInput, this);
    resizeEvent->setCallback(&SettingsForm::resize, this);

    eventManager->addEvent(sf::Event::MouseButtonPressed, mousePressEvenet);
    eventManager->addEvent(sf::Event::Resized, resizeEvent);

    layout = new Layout(0,0,window->getSize().x,window->getSize().y, sf::Color::Transparent);

    back_btn = new Button(0, 0, 100, 40, sf::Color::Green);
    back_btn->setTextContent("back");
    back_btn->setPosition(500, 500);
    back_btn->setCallback(new std::function<void()>([this](){
        this->requestForm("main");
    }));

    language_slct = new Selector(0,0, 200, 20, sf::Color::White);
    language_slct->testInit();
    language_slct->setWindow(this->window);

    resolution_slct = new Selector(0,0,200,20, sf::Color::White);
    resolution_slct->setWindow(this->window);

    layout->addChild(back_btn);
    layout->addChild(language_slct);
    layout->addChild(resolution_slct);
    language_slct->setParrent(layout);
    GUIPoll.push_back(layout);

    resolution_slct->setPosition(200,200);
    initResolution();
}

void SettingsForm::pollEvents()
{
    sf::Event event;
    while(window->pollEvent(event))
    {
        eventManager->handle(event);
    }
}

void SettingsForm::render()
{
    //REWRITE!!!!!
    window->clear(sf::Color::Black);
    //window->setView(GUIView);
    for(auto it : GUIPoll)
        window->draw(*it);
    window->display();
}

void SettingsForm::update()
{
    pollEvents();
    render();
}

void SettingsForm::mousePressInput(sf::Event event)
{
    mouseGUIInput();
}

void SettingsForm::resize(sf::Event event)
{
    GUIView.setSize(event.size.width, event.size.height);
    GUIView.setCenter(sf::Vector2f(event.size.width/2, event.size.height/2));
}

void SettingsForm::initResolution()
{
    resolution_slct->addChild("854 x 480");
    resolution_slct->addChild("960 x 540");
    resolution_slct->addChild("1024 x 576");
    resolution_slct->addChild("1136 x 640");
    resolution_slct->addChild("1280 х 720");
    resolution_slct->addChild("1366 х 768");
    resolution_slct->addChild("1440 x 864");
    resolution_slct->addChild("1600 x 900");
    resolution_slct->addChild("1920 x 1080");
    resolution_slct->select(0);
}
