#include <iostream>

#include "missile.hpp"

Missile::Missile()
{}

Missile::Missile(float x_pos, float y_pos, float window_side, float space, int side, float angle, float x_vel, float y_vel):
Shape(x_pos, y_pos, window_side, space), m_length(20), m_side(side), m_angle(angle)
{
    m_active = false;

    m_shape.setPointCount(4);
    m_shape.setPoint(0, sf::Vector2f(0, 0));
    m_shape.setPoint(1, sf::Vector2f(m_length / 4, 0));
    m_shape.setPoint(2, sf::Vector2f(m_length / 4, m_length));
    m_shape.setPoint(3, sf::Vector2f(0, m_length));

    m_shape.rotate(angle);

    m_shape.setFillColor(sf::Color(0, 0, 255));
    
    m_velocity.x = x_vel;
    m_velocity.y = y_vel;
}

bool Missile::ShapeUpdate()
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
    }
    
    return (true);
}

void Missile::ShapeHandler(sf::Event event, sf::Vector2f position, string side)
{
    if (event.key.code == sf::Keyboard::Space)
    {
        m_active = true;

        if ("Middle" == side)
        {
            m_position.x = position.x + (m_side * 10);
            m_position.y = position.y - 5;
        }
        else if ("Left" == side)
        {
            m_position.x = (position.x - 5) + (m_side * 10);
            m_position.y = position.y + 15;
        }
        else if ("Right" == side)
        {
            m_position.x = (position.x + 5) + (m_side * 10);
            m_position.y = position.y + 15;
        }
        else if ("D_Left" == side)
        {
            m_position.x = (position.x - 15) + (m_side * 10);
            m_position.y = position.y + 15;
        }
        else if ("D_Right" == side)
        {
            m_position.x = (position.x + 15) + (m_side * 10);
            m_position.y = position.y + 15;
        }
    }
}

void Missile::CheckBounds()
{
    if (m_space > m_position.y ||
        m_space > m_position.x || m_max_side + m_space < m_position.x)
    {
        m_active = false;
    }
}

bool Missile::Impact(Shape *other)
{
    bool vertical_check = false;
    bool horizontal_check = false;

    // Checking Vertical Distance
    if ((m_position.y < other->GetYPosition()) &&
        (m_position.y + m_length > other->GetYPosition() - other->GetLength()))
    {
        vertical_check = true;
    }

    // Checking Horizontal Distance
    if ((true == vertical_check) &&
        (m_position.x - (m_length * 0.20) < other->GetXPosition() + (other->GetLength() * 0.20)) &&
        (m_position.x + (m_length * 0.20) > other->GetXPosition() - (other->GetLength() * 0.20)))
    {
        horizontal_check = true;
    }

    if (horizontal_check == true)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

void Missile::AfterImpact()
{
    m_active = false;
}

void Missile::Draw(sf::RenderWindow &window_instance)
{
    if (true == m_active)
    {
        window_instance.draw(m_shape);
    }
}

void Missile::SetActive()
{
    m_active = true;
}