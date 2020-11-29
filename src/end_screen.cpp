
#include <iostream>

#include "end_screen.hpp"

EndScreen::EndScreen(float window_side, float space)
{
    m_window_side = window_side;
    m_space = space;

    m_screen = sf::RectangleShape(sf::Vector2f(window_side / 2, window_side / 2));
    
    m_screen.setFillColor(sf::Color(0, 0, 0));

    m_screen.setOutlineThickness(m_space / 4);
    m_screen.setOutlineColor(sf::Color(255, 255, 255));

    m_screen.setPosition(window_side / 4, window_side / 4);

    MainHeadLine();
    PressTo();
}

void EndScreen::MainHeadLine()
{
    if (!m_headline_font.loadFromFile("Raleway-BlackItalic.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }

    m_main_headline.setFont(m_headline_font);
    m_main_headline.setString("Game Over");
    m_main_headline.setPosition(sf::Vector2f(m_window_side * 0.37, 6 * m_space));
    m_main_headline.setCharacterSize(40);
    m_main_headline.setFillColor(sf::Color::Red);
    m_main_headline.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void EndScreen::PressTo()
{
    if (!m_to_start_font.loadFromFile("OpenSans-Italic.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }

    m_press_to_start.setFont(m_to_start_font);
    m_press_to_start.setString("Press ESCAPE to exit");
    m_press_to_start.setPosition(sf::Vector2f(m_window_side * 0.33, 12 * m_space));
    m_press_to_start.setCharacterSize(32);
    m_press_to_start.setFillColor(sf::Color::Red);
    m_press_to_start.setStyle(sf::Text::Bold);
}

void EndScreen::Draw(sf::RenderWindow &window_instance)
{
    window_instance.draw(m_screen);
    window_instance.draw(m_main_headline);
    window_instance.draw(m_press_to_start);
}