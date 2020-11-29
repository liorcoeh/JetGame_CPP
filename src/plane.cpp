
#include <iostream>

#include "plane.hpp"
#include "missile.hpp"
#include "power.hpp"
#include "live.hpp"

Plane::Plane(float x_pos, float y_pos, float window_side, float space):
Shape(x_pos, y_pos, window_side, space), m_mode(ONE), m_index(0)
{
    m_active = true;
    m_length = 75;
    m_name = "Main Plane";
    m_colide = "";
    m_power = 100;
    m_lives = 1;
    m_ammo = 100;
    m_score = 0;
    m_rand_time = 3;

    if (!m_font.loadFromFile("AlexBrush-Regular.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }

    m_power_gadget = new Power(window_side, space);

    InitializePlane();

    m_shape.setFillColor(sf::Color(0, 0, 255));

    m_shape.setPosition(x_pos, y_pos);

    InitializeLives();

    InitializeAmmo();
}

void Plane::InitializePlane()
{
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

    ScoreText();
}

void Plane::InitializeLives()
{
    m_lives_gadget[0] = new Live(m_max_side, m_space, m_max_side - m_space, m_max_side + (m_space));
    m_lives_gadget[1] = new Live(m_max_side, m_space, m_max_side - (0.5 * m_space), m_max_side + (m_space));
    m_lives_gadget[2] = new Live(m_max_side, m_space, m_max_side, m_max_side + (m_space));
    m_lives_gadget[3] = new Live(m_max_side, m_space, m_max_side + (0.5 * m_space), m_max_side + (m_space));
}

void Plane::InitializeAmmo()
{
    int left_side = -1;
    int mid_side = 0;
    int right_side = 1;
    float missiles_vel = 9;
    int up_dir = -1;
    int left_dir = -1;

    for (int i = 0; i < m_ammo; ++i) 
    {
        m_missile_middle[i] = new Missile(m_position.x, m_position.y, m_max_side, m_space, mid_side, 0, 0, up_dir * missiles_vel);

        m_missile_left[i] = new Missile(m_position.x, m_position.y, m_max_side, m_space, left_side, 0, 0, up_dir * missiles_vel);

        m_missile_right[i] = new Missile(m_position.x, m_position.y, m_max_side, m_space, right_side, 0, 0, up_dir * missiles_vel);

        m_missile_d_left[i] = new Missile(m_position.x, m_position.y, m_max_side, m_space, left_side, -45, left_dir * missiles_vel, up_dir * missiles_vel);

        m_missile_d_right[i] = new Missile(m_position.x, m_position.y, m_max_side, m_space, right_side, 45, missiles_vel, up_dir * missiles_vel);
    }

    AmmoText();
}

void Plane::AmmoText()
{
    m_ammo_text.setFont(m_font);
    m_ammo_text.setString(to_string(m_ammo));
    m_ammo_text.setPosition(sf::Vector2f(m_space * 2, m_max_side + m_space));
    m_ammo_text.setCharacterSize(32);
    m_ammo_text.setFillColor(sf::Color::Red);
    //m_ammo_text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void Plane::ScoreText()
{
    m_score_text.setFont(m_font);
    m_score_text.setString(to_string(m_score));
    m_score_text.setPosition(sf::Vector2f(m_space * 2, m_space * 0.25));
    m_score_text.setCharacterSize(32);
    m_score_text.setFillColor(sf::Color::Red);
    //m_score_text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void Plane::ShapeHandler(sf::Event event, sf::Vector2f position, string side)
{
    (void)position;
    (void)side;

    ChangeVelocity(event);

    m_position.x += m_velocity.x;
    m_position.y += m_velocity.y;

    m_shape.setPosition(m_position);
}

bool Plane::ShapeUpdate()
{
    m_power_gadget->Update(m_power);

    if (0 == m_lives)
    {
        return (false);
    }

    for (int i = 0; i < m_index; ++i)
    {
        if (ONE == m_mode)
        {
            m_missile_middle[i]->ShapeUpdate();
        }
        else if (TWO == m_mode)
        {
            m_missile_left[i]->ShapeUpdate();
            m_missile_right[i]->ShapeUpdate();
        }
        else if (THREE == m_mode)
        {
            m_missile_middle[i]->ShapeUpdate();
            m_missile_left[i]->ShapeUpdate();
            m_missile_right[i]->ShapeUpdate();
        }
        else
        {
            m_missile_middle[i]->ShapeUpdate();
            m_missile_left[i]->ShapeUpdate();
            m_missile_right[i]->ShapeUpdate();
            m_missile_d_left[i]->ShapeUpdate();
            m_missile_d_right[i]->ShapeUpdate();
        }
    }

    m_score_text.setString(to_string(m_score));
    
    if (false == m_active)
    {
        Died();
    }
    else
    {
        m_clock.restart();
    }
    
    return (true);
}

void Plane::ChangeVelocity(sf::Event event)
{
    if (true == m_active)
    {
        int vel = 7;

        switch (event.key.code)
        {
            case (sf::Keyboard::W):
            {
                if (m_space < m_position.y)
                {
                    m_velocity.x = 0 * vel;
                    m_velocity.y = (-1) * vel;
                }
                else
                {
                    m_velocity.x = 0 * vel;
                    m_velocity.y = 0 * vel;
                }
                
                break;
            }
            case (sf::Keyboard::S):
            {
                if (m_max_side + m_space > m_position.y + m_length)
                {
                    m_velocity.x = 0 * vel;
                    m_velocity.y = vel;
                }
                else
                {
                    m_velocity.x = 0 * vel;
                    m_velocity.y = 0 * vel;
                }
                break;
            }
            case (sf::Keyboard::A):
            {
                if (m_space < m_position.x - (m_length * 0.30))
                {
                    m_velocity.x = (-1) * vel;
                    m_velocity.y = 0 * vel;
                }
                else
                {
                    m_velocity.x = 0 * vel;
                    m_velocity.y = 0 * vel;
                }
                
                break;
            }
            case (sf::Keyboard::D):
            {
                if (m_max_side + m_space > m_position.x + (m_length * 0.30))
                {
                    m_velocity.x = vel;
                    m_velocity.y = 0 * vel;
                }
                else
                {
                    m_velocity.x = 0 * vel;
                    m_velocity.y = 0 * vel;
                }
                break;
            }
            case (sf::Keyboard::Q):
            {
                if (m_space < m_position.x - (m_length * 0.30) && m_space < m_position.y)
                {
                    m_velocity.x = (-1) * vel;
                    m_velocity.y = (-1) * vel;
                }
                else if (m_space < m_position.x - (m_length * 0.30))
                {
                    m_velocity.x = (-1) * vel;
                    m_velocity.y = 0 * vel;
                }
                else if (m_space < m_position.y)
                {
                    m_velocity.x = 0 * vel;
                    m_velocity.y = (-1) * vel;
                }
                else
                {
                    m_velocity.x = 0 * vel;
                    m_velocity.y = 0 * vel;
                }
                break;
            }
            case (sf::Keyboard::E):
            {
                if (m_max_side + m_space > m_position.x + (m_length * 0.30) && m_space < m_position.y)
                {
                    m_velocity.x = vel;
                    m_velocity.y = (-1) * vel;
                }
                else if (m_max_side  + m_space > m_position.x + (m_length * 0.30))
                {
                    m_velocity.x = vel;
                    m_velocity.y = 0 * vel;
                }
                else if (m_space < m_position.y)
                {
                    m_velocity.x = 0 * vel;
                    m_velocity.y = (-1) * vel;
                }
                else
                {
                    m_velocity.x = 0 * vel;
                    m_velocity.y = 0 * vel;
                }
                
                break;
            }
            case (sf::Keyboard::Z):
            {
                if (m_space < m_position.x - (m_length * 0.30) &&
                        m_max_side  + m_space > m_position.y + m_length)
                {
                    m_velocity.x = (-1) * vel;
                    m_velocity.y = vel;
                }
                else if (m_space < m_position.x - (m_length * 0.30))
                {
                    m_velocity.x = (-1) * vel;
                    m_velocity.y = 0 * vel;
                }
                else if (m_max_side  + m_space > m_position.y + m_length)
                {
                    m_velocity.x = 0 * vel;
                    m_velocity.y = vel;
                }
                else
                {
                    m_velocity.x = 0 * vel;
                    m_velocity.y = 0 * vel;
                }
                break;
            }
            case (sf::Keyboard::C):
            {
                if (m_max_side + m_space > m_position.x + (m_length * 0.30) &&
                            m_max_side + m_space > m_position.y + m_length)
                {
                    m_velocity.x = vel;
                    m_velocity.y = vel;
                }
                else if (m_max_side + m_space > m_position.x + (m_length * 0.30))
                {
                    m_velocity.x = vel;
                    m_velocity.y = 0 * vel;
                }
                else if (m_max_side + m_space > m_position.y + m_length)
                {
                    m_velocity.x = 0 * vel;
                    m_velocity.y = vel;
                }
                else
                {
                    m_velocity.x = 0 * vel;
                    m_velocity.y = 0 * vel;
                }
                
                break;
            }
            case (sf::Keyboard::Space):
            {
                m_velocity.x = 0;
                m_velocity.y = 0;

                Fire(event);

                break;
            }
            default:
            {
                m_velocity.x = 0;
                m_velocity.y = 0;

                break;
            }
        }
    }    
}

void Plane::Fire(sf::Event event)
{
    if (100 > m_index)
    {
        if (ONE == m_mode)
        {
            m_missile_middle[m_index]->ShapeHandler(event, m_position, "Middle");
        }
        else if (TWO == m_mode)
        {
            m_missile_left[m_index]->ShapeHandler(event, m_position, "Left");
            m_missile_right[m_index]->ShapeHandler(event, m_position, "Right");
        }
        else if (THREE == m_mode)
        {
            m_missile_middle[m_index]->ShapeHandler(event, m_position, "Middle");
            m_missile_left[m_index]->ShapeHandler(event, m_position, "Left");
            m_missile_right[m_index]->ShapeHandler(event, m_position, "Right");
        }
        else
        {
            m_missile_middle[m_index]->ShapeHandler(event, m_position, "Middle");
            m_missile_left[m_index]->ShapeHandler(event, m_position, "Left");
            m_missile_right[m_index]->ShapeHandler(event, m_position, "Right");
            m_missile_d_left[m_index]->ShapeHandler(event, m_position, "D_Left");
            m_missile_d_right[m_index]->ShapeHandler(event, m_position, "D_Right");
        }
        ++m_index;
        --m_ammo;
        m_ammo_text.setString(to_string(m_ammo));
    }
    else
    {
        std::cout << "OUT OF AMMO" << std::endl;
    }
}

bool Plane::Impact(Shape *other)
{
    if (true == m_active)
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
            m_colide = other->GetName();
            return (true);
        }
        else
        {
            return (false);
        }
    }
    else
    {
        return (false);
    }
    
}

void Plane::AfterImpact()
{
    if (m_colide == "Enemy Plane" || m_colide == "Enemy Missile")
    {
        m_power -= 25;

        if (50 > m_score)
        {
            m_score = 0;
        }
        else
        {
            m_score -= 50;
        }

        if (0 >= m_power)
        {
            m_power = 100;
            --m_lives;
            m_active = false;
        }

        m_mode = ONE;
    }
    else if (m_colide == "Ammo Reload")
    {
        m_index = 0;
        m_ammo = 100;
        InitializeAmmo();
    }
    else if (m_colide == "Ammo Change")
    {
        ChangeAmmo();
    }
    else if (m_colide == "Power Add")
    {
        if (100 > m_power)
        {
            m_power += 25;
        }
    }
    else if (m_colide == "Life Add")
    {
        if (4 > m_lives)
        {
            ++m_lives;
        }
    }
}

void Plane::AfterMissileHit()
{
    m_score += 100;
}

void Plane::Died()
{
    if (m_clock.getElapsedTime().asSeconds() > m_rand_time)
    {
        m_clock.restart();
        InitializeAmmo();
        m_mode = ONE;
        m_active = true;
    }
}  

void Plane::ChangeAmmo()
{
    m_index = 0;
    m_ammo = 100;
    InitializeAmmo();

    if (ONE == m_mode)
    {
        m_mode = TWO;
    }
    else if (TWO == m_mode)
    {
        m_mode = THREE;
    }
    else if (THREE == m_mode)
    {
        m_mode = ALL;
    }
    else
    {
        m_mode = ALL;
    }
}

void Plane::Draw(sf::RenderWindow &window_instance)
{
    if (true == m_active)
    {
        window_instance.draw(m_shape);
    }

    window_instance.draw(m_ammo_text);
    window_instance.draw(m_score_text);
    m_power_gadget->Draw(window_instance);

    for (int i = 0; i < m_lives - 1; ++i)
    {
        m_lives_gadget[i]->Draw(window_instance);
    }

    for (int i = 0; i < m_index; ++i)
    {
        if (ONE == m_mode)
        {
            m_missile_middle[i]->Draw(window_instance);
        }
        else if (TWO == m_mode)
        {
            m_missile_left[i]->Draw(window_instance);
            m_missile_right[i]->Draw(window_instance);
        }
        else if (THREE == m_mode)
        {
            m_missile_middle[i]->Draw(window_instance);
            m_missile_left[i]->Draw(window_instance);
            m_missile_right[i]->Draw(window_instance);
        }
        else
        {
            m_missile_middle[i]->Draw(window_instance);
            m_missile_left[i]->Draw(window_instance);
            m_missile_right[i]->Draw(window_instance);
            m_missile_d_left[i]->Draw(window_instance);
            m_missile_d_right[i]->Draw(window_instance);
        }
    }
}

sf::Vector2f& Plane::GetPosition()
{
    return (m_position);
}

Shape* Plane::GetMissileMid(int index)
{
    return (m_missile_middle[index]);
}

Shape* Plane::GetMissileLeft(int index)
{
    return (m_missile_left[index]);
}

Shape* Plane::GetMissileRight(int index)
{
    return (m_missile_right[index]);
}

Shape* Plane::GetMissileDLeft(int index)
{
    return (m_missile_d_left[index]);
}

Shape* Plane::GetMissileDRight(int index)
{
    return (m_missile_d_right[index]);
}