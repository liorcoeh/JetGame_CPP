
#include <iostream>

#include "enemy_missile.hpp"

EnenmyMissile::EnenmyMissile(float window_side, float space):
Shape(0, 0, window_side, space)
{
    m_active = false;
    m_length = 20;
    m_name = "Enemy Missile";

    m_shape.setPointCount(4);
    m_shape.setPoint(0, sf::Vector2f(0, 0));
    m_shape.setPoint(1, sf::Vector2f(m_length / 4, 0));
    m_shape.setPoint(2, sf::Vector2f(m_length / 4, m_length));
    m_shape.setPoint(3, sf::Vector2f(0, m_length));

    m_shape.rotate(180);

    m_shape.setFillColor(sf::Color(255, 0, 0));
    
    m_velocity.x = 0;
    m_velocity.y = 7;
}

bool EnenmyMissile::ShapeUpdate()
{
    if (true == m_active)
    {
        m_position.x += m_velocity.x;
        m_position.y += m_velocity.y;
        m_shape.setPosition(m_position);
        CheckBounds();
    }
    else
    {
        m_position.x = 1000;
        m_position.y = 1000;
        m_shape.setPosition(m_position);
    }

    return (true);
}

void EnenmyMissile::CheckBounds()
{
    if (m_max_side + m_space < m_position.y)
    {
        m_active = false;
    }
}

void EnenmyMissile::Draw(sf::RenderWindow &window_instance)
{
    if (true == m_active)
    {
        window_instance.draw(m_shape);
    }
}

void EnenmyMissile::SetActive()
{
    m_active = true;
}

// bool EnenmyMissile::Impact(Shape *other_shape)
// {

// }

void EnenmyMissile::AfterImpact()
{
    m_active = false;
}

void EnenmyMissile::SetPosition(sf::Vector2f position)
{
    m_position.x = position.x;
    m_position.y = position.y;
}

float EnenmyMissile::GetXPosition()
{
    return (m_position.x);
}

float EnenmyMissile::GetYPosition()
{
    return (m_position.y);
}

float EnenmyMissile::GetLength()
{
    return (m_length);
}

string& EnenmyMissile::GetName()
{
    return (m_name);
}