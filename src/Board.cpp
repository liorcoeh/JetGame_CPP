
#include <iostream>
#include <iterator>

#include "Board.hpp"
#include "plane.hpp"
#include "enemy.hpp"
#include "ammo_reload.hpp"
#include "ammo_change.hpp"
#include "power_add.hpp"
#include "life_add.hpp"

using namespace std;

Board::Board(float main_window_side)
{
    m_max_side = main_window_side - (main_window_side / 10);
    m_space = (main_window_side / 10) / 2;
    sf::RectangleShape new_board((sf::Vector2f(m_max_side, m_max_side)));

    m_board = new_board;

    m_board.setFillColor(sf::Color(30, 30, 30));
    m_board.setPosition(m_space, m_space);

    m_board.setOutlineThickness(10.f);
    m_board.setOutlineColor(sf::Color(0, 0, 0));

    m_num_of_enenmy_planes = 20;

    m_restart_time = ((((m_space * m_num_of_enenmy_planes) + m_max_side) / m_max_side) * 10) + 15;

    InitializeBoard();
}

void Board::InitializeBoard()
{
    m_plane = new Plane((m_max_side / 2) + m_space, m_max_side - (m_max_side / 10), m_max_side, m_space);

    srand(time(0));

    for (int i = 0; i < m_num_of_enenmy_planes; ++i)    // Initialize Enemy Planes
    {
       m_enemy.push_back(new Enemy(m_max_side, m_space, i + 1));
    }

    m_dif.push_back(new AmmoReload(m_max_side, m_space));
    m_dif.push_back(new AmmoChange(m_max_side, m_space));
    m_dif.push_back(new PowerAdd(m_max_side, m_space));
    m_dif.push_back(new LifeAdd(m_max_side, m_space));
}

void Board::BoardHandler(sf::Event event)
{
    if (event.type == sf::Event::EventType::KeyPressed)
    {
        m_plane->ShapeHandler(event, m_plane->GetPosition(), "");
    }
}

bool Board::BoardUpdate()
{
    if (false == m_plane->ShapeUpdate())
    {
        return (false);
    }

    vector<Shape*>::iterator iter;

    for (iter = m_enemy.begin(); iter != m_enemy.end(); ++iter)
    {
        (*iter)->ShapeUpdate();
    }

    if (m_clock.getElapsedTime().asSeconds() > m_restart_time)
    {
        EnemyRestart();
        m_clock.restart();
    }

    for (iter = m_dif.begin(); iter != m_dif.end(); ++iter)
    {
        (*iter)->ShapeUpdate();
    }

    Colisions();

    return (true);
}

void Board::EnemyRestart()
{
    vector<Shape*>::iterator iter;
    int i = 0;

    for (iter = m_enemy.begin(); iter != m_enemy.end(); ++iter)
    {
        (*iter) = new Enemy(m_max_side, m_space, i + 1);
        ++i;
    }
}

void Board::Colisions()
{
    vector<Shape*>::iterator iter;

    // Main Plane missiles hitting enemy planes
    for (iter = m_enemy.begin(); iter != m_enemy.end(); ++iter)
    {
        for (int i = 0; i < 100; ++i)
        {
            if (true == m_plane->GetMissileMid(i)->Impact(*iter))
            {
                m_plane->GetMissileMid(i)->AfterImpact();
                (*iter)->AfterImpact();
                m_plane->AfterMissileHit();
            }

            if (true == m_plane->GetMissileLeft(i)->Impact(*iter))
            {
                m_plane->GetMissileLeft(i)->AfterImpact();
                (*iter)->AfterImpact();
                m_plane->AfterMissileHit();
            }

            if (true == m_plane->GetMissileRight(i)->Impact(*iter))
            {
                m_plane->GetMissileRight(i)->AfterImpact();
                (*iter)->AfterImpact();
                m_plane->AfterMissileHit();
            }

            if (true == m_plane->GetMissileDLeft(i)->Impact(*iter))
            {
                m_plane->GetMissileDLeft(i)->AfterImpact();
                (*iter)->AfterImpact();
                m_plane->AfterMissileHit();
            }

            if (true == m_plane->GetMissileDRight(i)->Impact(*iter))
            {
                m_plane->GetMissileDRight(i)->AfterImpact();
                (*iter)->AfterImpact();
                m_plane->AfterMissileHit();
            }
        }
    }

    // Main Plane is being hit by enemy planes / enemy missiles
    for (iter = m_enemy.begin(); iter != m_enemy.end(); ++iter)
    {
        if (true == m_plane->Impact(*iter)) // Colliding with enemy planes
        {
            m_plane->AfterImpact();
            (*iter)->AfterImpact();
        }

        for (int i = 0; i < 10; ++i) // Colliding with enemy missiles
        {
            Shape* missile = (*iter)->GetMissile(i);
            if (true == m_plane->Impact(missile))
            {
                m_plane->AfterImpact();
                missile->AfterImpact();
            }
        }
    }

    // Main Plane is being hit by different upgrades
    for (iter = m_dif.begin(); iter != m_dif.end(); ++iter)
    {
        if (true == m_plane->Impact(*iter))
        {
            m_plane->AfterImpact();
            (*iter)->AfterImpact();
        }
    }
}


void Board::DrawBoard(sf::RenderWindow &window_instance)
{
    window_instance.draw(m_board);

    m_plane->Draw(window_instance);
    
    vector<Shape*>::iterator iter;

    for (iter = m_enemy.begin(); iter != m_enemy.end(); ++iter)
    {
        (*iter)->Draw(window_instance);
    }

    for (iter = m_dif.begin(); iter != m_dif.end(); ++iter)
    {
        (*iter)->Draw(window_instance);
    }
}



