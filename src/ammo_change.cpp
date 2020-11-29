
#include <iostream>

#include "ammo_change.hpp"

AmmoChange::AmmoChange(float window_side, float space):
Shape(0, 0, window_side, space), m_shape(15)
{
    m_active = false;
    m_length = 100;
    m_name = "Ammo Change";

    RandomStartingPosition();

    m_shape.setFillColor(sf::Color(51, 51, 255));
    m_shape.setOutlineThickness(1);
    m_shape.setOutlineColor(sf::Color(250, 150, 100));

    SetVelocity();

    m_rand_time = (rand() % 30) + 30;
}

bool AmmoChange::ShapeUpdate()
{
    if (true == m_active)
    {
        m_position.y += m_velocity.y;

        m_shape.setPosition(m_position);
        CheckBounds();
    }
    else
    {
        m_position.x = m_max_side + 100;
        m_position.y = m_max_side + 100;
        m_shape.setPosition(m_position);
        Restart();
    }

    return (true);
}

void AmmoChange::CheckBounds()
{
    if (m_max_side < m_position.y)
    {
        m_active = false;
    }
}

void AmmoChange::RandomStartingPosition()
{
    m_position.x = (rand() % ((int)m_max_side - (2 * ((int)m_max_side / 10)))) + m_space;
    m_position.y = m_space;
}

void AmmoChange::SetVelocity()
{
    m_velocity.y = (rand() % 5) + 4;
}

void AmmoChange::Restart()
{
    if (m_clock.getElapsedTime().asSeconds() > m_rand_time)
    {
        RandomStartingPosition();
        SetVelocity();
        m_clock.restart();
        m_rand_time = (rand() % 30) + 30;
        m_active = true;
    }
}

void AmmoChange::Draw(sf::RenderWindow &window_instance)
{
    window_instance.draw(m_shape);
}

// bool AmmoChange::Impact(Shape *other_shape)
// {

// }

void AmmoChange::AfterImpact()
{
    m_active = false;
}

float AmmoChange::GetXPosition()
{
    return (m_position.x);
}

float AmmoChange::GetYPosition()
{
    return (m_position.y);
}

float AmmoChange::GetLength()
{
    return (m_length);
}

string& AmmoChange::GetName()
{
    return (m_name);
}