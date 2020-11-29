
#include <iostream>

#include "shapes.hpp"

Shape::Shape(float x_pos, float y_pos, float window_side, float space):
m_position(x_pos, y_pos), m_velocity(0, 0), m_max_side(window_side), m_space(space)
{}

void Shape::ShapeHandler(sf::Event event, sf::Vector2f position, string side)
{
    cout << "In Shape Update" << endl;
    (void)event;
    (void)position;
    (void)side;
}

bool Shape::ShapeUpdate()
{
    cout << "In Shape ShapeUpdate" << endl;
    return (true);
}

void Shape::ChangeVelocity(sf::Event event)
{
    cout << "In Shape SetVelocity" <<endl;
    (void)event;
}

void Shape::SetVelocity()
{
    cout << "In Shape ChangeVelocity" << endl;
}

void Shape::CheckBounds()
{
    cout << "In Shape " << endl;
}

void Shape::Draw(sf::RenderWindow &window_instance)
{
    cout << "In Shape Draw" << endl;
    (void)window_instance;
}

sf::Vector2f& Shape::GetPosition()
{
    cout << "In Shape GetPosition" << endl;
    return (m_position);
}

bool Shape::Impact(Shape *other_shape)
{
    (void)other_shape;
    cout << "In Shape Impact" << endl;
}

void Shape::AfterImpact()
{
    cout << "In Shape AfterImpact" << endl;
}

void Shape::AfterMissileHit()
{
    cout << "In Shape AfterMissileHit" << endl;
}

void Shape::SetActive()
{
    cout << "In Shape SetActive" << endl;
}

bool Shape::GetActive()
{
    cout << "In Shape GetActive" << endl;
    return (true);
}

void Shape::SetPosition(sf::Vector2f position)
{
    cout << "In Shape SetPosition" << endl;
    (void)position;
}

float Shape::GetXPosition()
{
    cout << "In Shape GetXPosition" << endl;
    return (m_position.x);
}

float Shape::GetYPosition()
{
    cout << "In Shape GetYPosition" << endl;
    return (m_position.y);
}

float Shape::GetLength()
{
    cout << "In Shape GetLength" << endl;
    return (m_length);
}

string& Shape::GetName()
{
    cout << "In Shape GetName" << endl;
    return (m_name);
}

Shape* Shape::GetMissile(int index)
{
    (void)index;
    cout << "In Shape GetMissile" << endl;
    return (NULL);
}

Shape* Shape::GetMissileMid(int index)
{
    (void)index;
    cout << "In Shape GetMissileMid" << endl;
    return (NULL);
}

Shape* Shape::GetMissileLeft(int index)
{
    (void)index;
    cout << "In Shape GetMissileLeft" << endl;
    return (NULL);
}

Shape* Shape::GetMissileRight(int index)
{
    (void)index;
    cout << "In Shape GetMissileRight" << endl;
    return (NULL);
}

Shape* Shape::GetMissileDLeft(int index)
{
    (void)index;
    cout << "In Shape GetMissileDLeft" << endl;
    return (NULL);
}

Shape* Shape::GetMissileDRight(int index)
{
    (void)index;
    cout << "In Shape GetMissileDRight" << endl;
    return (NULL);
}