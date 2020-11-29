#ifndef AMMO_CHANGE_HPP
#define AMMO_CHANGE_HPP

#include <SFML/Graphics.hpp>

#include "shapes.hpp"

class AmmoChange : public Shape
{
public:

    AmmoChange(float window_side, float space);

    ~AmmoChange()
    {}

    bool ShapeUpdate();

    void CheckBounds();

    void RandomStartingPosition();

    void SetVelocity();

    void Restart();

    void Draw(sf::RenderWindow &window_instance);

    //bool Impact(Shape *other_shape);

    void AfterImpact();

    float GetXPosition();

    float GetYPosition();

    float GetLength();

    string& GetName();

private:
    sf::CircleShape m_shape;
    int m_index;
    sf::Clock m_clock;
    int m_rand_time;
};

#endif // AMMO_CHANGE_HPP