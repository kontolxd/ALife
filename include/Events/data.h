#include <SFML/Graphics.hpp>

union Data
{
    Data();
    //For resize event
    struct
    {
        int width;
        int height;
    } size;
    //For mouse scroll event
    struct
    {
        int x, y;
        int delta;
    } mouseScroll;
    //For click event
    struct
    {
        int x, y;
        sf::Mouse::Button button;
    } mouseButton;
    //For mouse move event
    struct
    {
        int x, y;
    } mouseMove;
    //For keyboard event
    sf::Keyboard::Key key;
    //For text entered event
    std::string text;
};
