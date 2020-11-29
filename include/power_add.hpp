#ifndef POWER_ADD_HPP
#define POWER_ADD_HPP

#include <SFML/Graphics.hpp>

#include "shapes.hpp"

class PowerAdd : public Shape
{
public:
    PowerAdd(float window_side, float space);

    ~PowerAdd()
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
    sf::RectangleShape m_shape;
    int m_index;
    sf::Clock m_clock;
    int m_rand_time;
};

#endif // POWER_ADD_HPP