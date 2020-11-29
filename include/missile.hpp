#ifndef MISSILE_HPP
#define MISSILE_HPP

#include <SFML/Graphics.hpp>

#include "shapes.hpp"

class Missile : public Shape
{
public:
    Missile();

    Missile(float x_pos, float y_pos, float window_side, float space, int side, float angle, float x_vel, float y_vel);

    ~Missile()
    {}

    void ShapeHandler(sf::Event event, sf::Vector2f position, string side);
    
    bool ShapeUpdate();

    void CheckBounds();

    void Draw(sf::RenderWindow &window_instance);

    bool Impact(Shape *other_shape);

    void AfterImpact();

    void SetActive();

private:
    double m_length;
    int m_side; // Left / Middle / Right
    float m_angle;
};

#endif // MISSILE_HPP