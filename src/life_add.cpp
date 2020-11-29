
#include <iostream>

#include "life_add.hpp"

LifeAdd::LifeAdd(float window_side, float space):
Shape(0, 0, window_side, space), m_shape(sf::Vector2f(15, 15))
{
    m_active = true;
    m_length = 100;
    m_name = "Life Add";

    RandomStartingPosition();

    m_shape.setFillColor(sf::Color(0, 255, 0));
    m_shape.setOutlineThickness(1);
    m_shape.setOutlineColor(sf::Color(250, 150, 100));

    SetVelocity();

    m_rand_time = (rand() % 60) + 30;
}

bool LifeAdd::ShapeUpdate()
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

void LifeAdd::CheckBounds()
{
    if (m_max_side < m_position.y)
    {
        m_active = false;
    }
}

void LifeAdd::RandomStartingPosition()
{
    m_position.x = (rand() % ((int)m_max_side - (2 * ((int)m_max_side / 10)))) + m_space;
    m_position.y = m_space;
}

void LifeAdd::SetVelocity()
{
    m_velocity.y = (rand() % 5) + 4;
}

void LifeAdd::Restart()
{
    if (m_clock.getElapsedTime().asSeconds() > m_rand_time)
    {
        RandomStartingPosition();
        SetVelocity();
        m_clock.restart();
        m_rand_time = (rand() % 60) + 30;
    }
}

void LifeAdd::Draw(sf::RenderWindow &window_instance)
{
    window_instance.draw(m_shape);
}

// bool LifeAdd::Impact(Shape *other_shape)
// {

// }

void LifeAdd::AfterImpact()
{
    m_active = false;
}

float LifeAdd::GetXPosition()
{
    return (m_position.x);
}

float LifeAdd::GetYPosition()
{
    return (m_position.y);
}

float LifeAdd::GetLength()
{
    return (m_length);
}

string& LifeAdd::GetName()
{
    return (m_name);
}