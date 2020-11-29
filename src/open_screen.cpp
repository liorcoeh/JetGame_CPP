
#include <iostream>

#include "open_screen.hpp"

OpenScreen::OpenScreen(float window_side, float space)
{
    m_window_side = window_side;
    m_space = space;

    m_screen = sf::RectangleShape(sf::Vector2f(window_side - m_space, window_side - m_space));

    m_screen.setFillColor(sf::Color(0, 0, 0));

    m_screen.setOutlineThickness(m_space / 2);
    m_screen.setOutlineColor(sf::Color(250, 150, 100));

    m_screen.setPosition(m_space / 2, m_space / 2);

    MainHeadLine();
    PressTo();
}

void OpenScreen::MainHeadLine()
{
    if (!m_headline_font.loadFromFile("Raleway-BlackItalic.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }

    m_main_headline.setFont(m_headline_font);
    m_main_headline.setString("2020 JetFighter");
    m_main_headline.setPosition(sf::Vector2f(m_window_side * 0.3, 3 * m_space));
    m_main_headline.setCharacterSize(52);
    m_main_headline.setFillColor(sf::Color::Red);
    m_main_headline.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void OpenScreen::PressTo()
{
    if (!m_to_start_font.loadFromFile("OpenSans-Italic.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }

    m_press_to_start.setFont(m_to_start_font);
    m_press_to_start.setString("Press SPACE to start");
    m_press_to_start.setPosition(sf::Vector2f(m_window_side * 0.3, 15 * m_space));
    m_press_to_start.setCharacterSize(42);
    m_press_to_start.setFillColor(sf::Color::Red);
    m_press_to_start.setStyle(sf::Text::Bold);
}

void OpenScreen::Draw(sf::RenderWindow &window_instance)
{
    window_instance.draw(m_screen);
    window_instance.draw(m_main_headline);
    window_instance.draw(m_press_to_start);
}