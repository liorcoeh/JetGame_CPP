
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "enemy.hpp"
#include "enemy_missile.hpp"

Enemy::Enemy(float window_side, float space, int num):
Shape(0, 0, window_side, space), m_num(num), m_index(0)
{
    m_active = true;
    m_length = 75;
    m_name = "Enemy Plane";

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

    RandomStartingPosition();

    m_shape.setFillColor(sf::Color(255, 0 ,0));

    m_shape.setPosition(m_position.x, m_position.y);

    m_shape.rotate(180);

    SetVelocity();

    InitializeAmmo();

    m_rand_time = (rand() % 1) + 1;
}

void Enemy::InitializeAmmo()
{
    for (int i = 0; i < 10; ++i) 
    {
        m_missile[i] = new EnenmyMissile(m_max_side, m_space);
    }
}

bool Enemy::ShapeUpdate()
{
    if (true == m_active)
    {
        if (m_position.y < 200)
        {
            m_position.x += 0;
        }
        else
        {
            m_position.x += m_velocity.x;
        }
        m_position.x += 0;
        m_position.y += m_velocity.y;

        m_shape.setPosition(m_position);

        CheckBounds();

        if (m_space + (m_length * 0.5) < m_position.y)
        {
            Fire();
        }
    }
    else
    {
        m_position.x = 1000;
        m_position.y = 1000;
        m_shape.setPosition(m_position);
    }

    for (int i = 0; i < m_index; ++i)
    {
        m_missile[i]->ShapeUpdate();
    }

    return (true);
}

void Enemy::Fire()
{
    if (m_clock.getElapsedTime().asSeconds() > m_rand_time)
    {
        m_missile[m_index]->SetActive();
        m_missile[m_index]->SetPosition(m_position);
        m_clock.restart();
        m_rand_time = (rand() % 2) + 1;
        ++m_index;
    }
}

void Enemy::Draw(sf::RenderWindow &window_instance)
{
    
    if (m_space + (m_length * 0.5) < m_position.y)
    {
        window_instance.draw(m_shape);
    }

    for (int i = 0; i < m_index; ++i)
    {
        m_missile[i]->Draw(window_instance);
    }
}

void Enemy::RandomStartingPosition()
{
    m_position.x = (rand() % ((int)m_max_side - ((int)m_max_side / 10))) + m_space;
    m_position.y = m_space - (2 * m_space * m_num);
}

void Enemy::CheckBounds()
{
    if (m_max_side + (m_space / 2) < m_position.y ||
        m_space > m_position.x || m_max_side < m_position.x)
    {
        m_active = false;
    }
}

void Enemy::SetVelocity()
{
    m_starting_velocity.x = 0;
    m_starting_velocity.y = 0;

    int direction = (rand() % 3 - 1); // -1->left, 0->down, 1->right

    m_velocity.x = ((rand() % 2) + 3) * direction;
    m_velocity.y = (rand() % 2) + 3;
}

// bool Enemy::Impact(Shape *other_shape)
// {
    
// }

void Enemy::AfterImpact()
{
    m_active = false;
}

bool Enemy::GetActive()
{
    return (m_active);
}

float Enemy::GetXPosition()
{
    return (m_position.x);
}

float Enemy::GetYPosition()
{
    return (m_position.y);
}

float Enemy::GetLength()
{
    return (m_length);
}

string& Enemy::GetName()
{
    return (m_name);
}

Shape* Enemy::GetMissile(int index)
{
    return (m_missile[index]);
}