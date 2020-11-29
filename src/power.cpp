#include <iostream>

#include "power.hpp"

Power::Power(float window_side, float space): Gadget(window_side, space)
{
    m_length = 200;
    m_amount = 100;

    m_shape.setPointCount(4);

    m_shape.setPoint(0, sf::Vector2f(0, 0));
    m_shape.setPoint(1, sf::Vector2f(m_space / 2, 0));
    m_shape.setPoint(2, sf::Vector2f(m_space / 2, m_length));
    m_shape.setPoint(3, sf::Vector2f(0, m_length));

    m_shape.setFillColor(sf::Color::Green);

    m_shape.setPosition(m_max_side + (1.25 * m_space), 3 * m_space);
}

void Power::Update(int power)
{
    switch (power)
    {
        case (100):
        {
            m_shape.setPoint(0, sf::Vector2f(0, 0));
            m_shape.setPoint(1, sf::Vector2f(m_space / 2, 0));
            m_shape.setPoint(2, sf::Vector2f(m_space / 2, m_length));
            m_shape.setPoint(3, sf::Vector2f(0, m_length));

            m_shape.setFillColor(sf::Color::Green);
            break;
        }
        case (75):
        {
            m_shape.setPoint(0, sf::Vector2f(0, 0));
            m_shape.setPoint(1, sf::Vector2f(m_space / 2, 0));
            m_shape.setPoint(2, sf::Vector2f(m_space / 2, (0.75 *m_length)));
            m_shape.setPoint(3, sf::Vector2f(0, (0.75 *m_length)));

            m_shape.setFillColor(sf::Color::Green);
            break;
        }
        case (50):
        {
            m_shape.setPoint(0, sf::Vector2f(0, 0));
            m_shape.setPoint(1, sf::Vector2f(m_space / 2, 0));
            m_shape.setPoint(2, sf::Vector2f(m_space / 2, (0.50 *m_length)));
            m_shape.setPoint(3, sf::Vector2f(0, (0.50 *m_length)));

            m_shape.setFillColor(sf::Color::Red);
            break;
        }
        case (25):
        {
            m_shape.setPoint(0, sf::Vector2f(0, 0));
            m_shape.setPoint(1, sf::Vector2f(m_space / 2, 0));
            m_shape.setPoint(2, sf::Vector2f(m_space / 2, (0.25 *m_length)));
            m_shape.setPoint(3, sf::Vector2f(0, (0.25 *m_length)));

            m_shape.setFillColor(sf::Color::Red);
            break;
        }
        case (0):
        {
            m_shape.setPoint(0, sf::Vector2f(0, 0));
            m_shape.setPoint(1, sf::Vector2f(m_space / 2, 0));
            m_shape.setPoint(2, sf::Vector2f(m_space / 2, 0));
            m_shape.setPoint(3, sf::Vector2f(0, 0));

            m_shape.setFillColor(sf::Color::Green);
            break;
        }
    }
}

void Power::Draw(sf::RenderWindow &window_instance)
{
    window_instance.draw(m_shape);
}