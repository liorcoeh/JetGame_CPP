#ifndef LIFE_ADD_HPP
#define LIFE_ADD_HPP

#include <SFML/Graphics.hpp>

#include "shapes.hpp"

class LifeAdd : public Shape
{
public:
    LifeAdd(float window_side, float space);

    ~LifeAdd()
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

#endif // LIFE_ADD_HPP