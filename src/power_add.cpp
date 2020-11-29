
#include <iostream>

#include "power_add.hpp"

PowerAdd::PowerAdd(float window_side, float space):
Shape(0, 0, window_side, space), m_shape(sf::Vector2f(15, 15))
{
    m_active = true;
    m_length = 100;
    m_name = "Power Add";

    RandomStartingPosition();

    m_shape.setFillColor(sf::Color(255, 255, 0));
    m_shape.setOutlineThickness(1);
    m_shape.setOutlineColor(sf::Color(250, 150, 100));

    SetVelocity();

    m_rand_time = (rand() % 60) + 15;
}

bool PowerAdd::ShapeUpdate()
{
    if (true == m_active)
    {
        m_position.y += m_velocity.y;

        m_shape.rotate(4);
        m_shape.setPosition(m_position);
        CheckBounds();
    }
    else
    {
        m_position.x = 1000;
        m_position.y = 1000;
        m_shape.setPosition(m_position);
        Restart();
    }

    return (true);
}

void PowerAdd::CheckBounds()
{
    if (m_max_side < m_position.y)
    {
        m_active = false;
    }
}

void PowerAdd::RandomStartingPosition()
{
    m_position.x = (rand() % ((int)m_max_side - (2 * ((int)m_max_side / 10)))) + m_space;
    m_position.y = m_space;
}

void PowerAdd::SetVelocity()
{
    m_velocity.y = (rand() % 5) + 4;
}

void PowerAdd::Restart()
{
    if (m_clock.getElapsedTime().asSeconds() > m_rand_time)
    {
        RandomStartingPosition();
        SetVelocity();
        m_clock.restart();
        m_rand_time = (rand() % 60) + 15;
    }
}

void PowerAdd::Draw(sf::RenderWindow &window_instance)
{
    window_instance.draw(m_shape);
}

// bool PowerAdd::Impact(Shape *other_shape)
// {

// }

void PowerAdd::AfterImpact()
{
    m_active = false;
}

float PowerAdd::GetXPosition()
{
    return (m_position.x);
}

float PowerAdd::GetYPosition()
{
    return (m_position.y);
}

float PowerAdd::GetLength()
{
    return (m_length);
}

string& PowerAdd::GetName()
{
    return (m_name);
}