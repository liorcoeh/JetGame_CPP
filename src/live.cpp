#include <iostream>

#include "live.hpp"

Live::Live(float window_side, float space, float pos_x, float pos_y): Gadget(window_side, space)
{
    m_length = 0.5 * m_space;
    m_amount = 1;

    m_shape.setPointCount(17);

    m_shape.setPoint(0, sf::Vector2f(0, 0));
    m_shape.setPoint(1, sf::Vector2f(0.05 * m_length, 0.2 * m_length));
    m_shape.setPoint(2, sf::Vector2f(0.05 * m_length, 0.4 * m_length));
    m_shape.setPoint(3, sf::Vector2f(0.25 * m_length, 0.55 * m_length));
    m_shape.setPoint(4, sf::Vector2f(0.25 * m_length, 0.65 * m_length));
    m_shape.setPoint(5, sf::Vector2f(0.05 * m_length, 0.6 * m_length));
    m_shape.setPoint(6, sf::Vector2f(0.05 * m_length, 0.85 * m_length));
    m_shape.setPoint(7, sf::Vector2f(0.15 * m_length, 0.95 * m_length));
    m_shape.setPoint(8, sf::Vector2f(0.15 * m_length, m_length));
    m_shape.setPoint(9, sf::Vector2f(-0.15 * m_length, m_length));
    m_shape.setPoint(10, sf::Vector2f(-0.15 * m_length, 0.95 * m_length));
    m_shape.setPoint(11, sf::Vector2f(-0.05 * m_length, 0.85 * m_length));
    m_shape.setPoint(12, sf::Vector2f(-0.05 * m_length, 0.6 * m_length));
    m_shape.setPoint(13, sf::Vector2f(-0.25 * m_length, 0.65 * m_length));
    m_shape.setPoint(14, sf::Vector2f(-0.25 * m_length, 0.55 * m_length));
    m_shape.setPoint(15, sf::Vector2f(-0.05 * m_length, 0.4 * m_length));
    m_shape.setPoint(16, sf::Vector2f(-0.05 * m_length, 0.2 * m_length));

    m_shape.setFillColor(sf::Color::Blue);

    m_shape.setPosition(pos_x, pos_y);
}

void Live::Draw(sf::RenderWindow &window_instance)
{
    window_instance.draw(m_shape);
}