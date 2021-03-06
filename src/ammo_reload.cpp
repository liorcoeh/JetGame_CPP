
#include <iostream>

#include "ammo_reload.hpp"

AmmoReload::AmmoReload(float window_side, float space):
Shape(0, 0, window_side, space), m_shape(15)
{
    m_active = false;
    m_length = 100;
    m_name = "Ammo Reload";

    RandomStartingPosition();

    m_shape.setFillColor(sf::Color(255, 255, 0));
    m_shape.setOutlineThickness(1);
    m_shape.setOutlineColor(sf::Color(250, 150, 100));

    SetVelocity();

    m_rand_time = (rand() % 30) + 15;
}

bool AmmoReload::ShapeUpdate()
{
    if (true == m_active)
    {
        m_position.y += m_velocity.y;

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

void AmmoReload::CheckBounds()
{
    if (m_max_side < m_position.y)
    {
        m_active = false;
    }
}

void AmmoReload::RandomStartingPosition()
{
    m_position.x = (rand() % ((int)m_max_side - (2 * ((int)m_max_side / 10)))) + m_space;
    m_position.y = m_space;
}

void AmmoReload::SetVelocity()
{
    m_velocity.y = (rand() % 5) + 4;
}

void AmmoReload::Restart()
{
    if (m_clock.getElapsedTime().asSeconds() > m_rand_time)
    {
        RandomStartingPosition();
        SetVelocity();
        m_clock.restart();
        m_rand_time = (rand() % 30) + 15;
        m_active = true;
    }
}

void AmmoReload::Draw(sf::RenderWindow &window_instance)
{
    window_instance.draw(m_shape);
}

// bool AmmoReload::Impact(Shape *other_shape)
// {

// }

void AmmoReload::AfterImpact()
{
    m_active = false;
}

float AmmoReload::GetXPosition()
{
    return (m_position.x);
}

float AmmoReload::GetYPosition()
{
    return (m_position.y);
}

float AmmoReload::GetLength()
{
    return (m_length);
}

string& AmmoReload::GetName()
{
    return (m_name);
}