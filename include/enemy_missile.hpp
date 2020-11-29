#ifndef ENEMY_MISSILE_HPP
#define ENEMY_MISSILE_HPP

#include <SFML/Graphics.hpp>

#include "shapes.hpp"

class EnenmyMissile : public Shape
{
public:
    EnenmyMissile(float window_side, float space);

    ~EnenmyMissile()
    {}
    
    bool ShapeUpdate();

    void CheckBounds();

    void Draw(sf::RenderWindow &window_instance);

    //bool Impact(Shape *other_shape);

    void AfterImpact();

    void SetPosition(sf::Vector2f position);

    float GetXPosition();

    float GetYPosition();

    float GetLength();

    string& GetName();

    void SetActive();

private:
    float m_angle;
};

#endif // ENEMY_MISSILE_HPP