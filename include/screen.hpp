#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>

class Screen
{
public:
    Screen()
    {}

    Screen(float window_side, float space);

    virtual ~Screen()
    {}

    virtual void MainHeadLine();

    virtual void PressTo();

    virtual void Draw(sf::RenderWindow &window_instance);

protected:
    float m_window_side;
    float m_space;
    sf::RectangleShape m_screen;
    sf::Text m_main_headline;
    sf::Font m_headline_font;

    sf::Text m_press_to_start;
    sf::Font m_to_start_font;

    sf::Text m_second;
};

#endif // SCREEN_HPP