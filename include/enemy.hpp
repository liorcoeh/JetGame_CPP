#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>

#include "shapes.hpp"

class Enemy : public Shape
{
public:
    Enemy(float window_side, float space, int num);

    ~Enemy()
    {}

    bool ShapeUpdate();

    void SetVelocity();

    void InitializeAmmo();

    void Restart();

    void Fire();

    void CheckBounds();

    void Draw(sf::RenderWindow &window_instance);

    void RandomStartingPosition();

    //bool Impact(Shape *other_shape);

    void AfterImpact();

    //void SetActive();

    bool GetActive();

    float GetXPosition();

    float GetYPosition();

    float GetLength();

    string& GetName();

    Shape* GetMissile(int index);

private:
    sf::Vector2f m_starting_velocity;
    Shape* m_missile[10];
    int m_num;
    int m_index;
};

#endif //ENEMY_HPP