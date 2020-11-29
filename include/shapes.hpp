#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <SFML/Graphics.hpp>

using namespace std;

class Shape
{
public:
    Shape()
    {}

    Shape(float x_pos, float y_pos, float window_side, float space);

    virtual ~Shape()
    {}

    virtual void ShapeHandler(sf::Event event, sf::Vector2f position, string side);

    virtual bool ShapeUpdate();

    virtual void ChangeVelocity(sf::Event event); // // For main plane

    virtual void SetVelocity();

    virtual void CheckBounds();

    virtual void Draw(sf::RenderWindow &window_instance);

    virtual sf::Vector2f& GetPosition();

    virtual void SetPosition(sf::Vector2f position);

    virtual float GetXPosition();

    virtual float GetYPosition();

    virtual float GetLength();

    virtual bool Impact(Shape *other_shape);

    virtual void AfterImpact();

    virtual void AfterMissileHit();

    virtual void SetActive();

    virtual bool GetActive();

    virtual string& GetName();

    virtual Shape* GetMissile(int index);

    virtual Shape* GetMissileMid(int index);

    virtual Shape* GetMissileLeft(int index);

    virtual Shape* GetMissileRight(int index);

    virtual Shape* GetMissileDLeft(int index);

    virtual Shape* GetMissileDRight(int index);

protected:
    sf::ConvexShape m_shape;
    sf::Vector2f m_position;
    sf::Vector2f m_velocity;
    float m_max_side;
    float m_space;
    bool m_active;
    float m_length;
    string m_name;
    sf::Clock m_clock;
    int m_rand_time;
};

#endif // SHAPES_HPP