#ifndef PLANE_HPP
#define PLANE_HPP

#include <vector>
#include <iterator>
#include <SFML/Graphics.hpp>

#include "shapes.hpp"
#include "gadget.hpp"

class Plane : public Shape
{
public:
    enum MISSILES_MODE
    {
        ONE = 1,
        TWO,
        THREE,
        ALL
    };

    Plane(float x_pos, float y_pos, float window_side, float space);

    ~Plane()
    {}

    void InitializePlane();

    void InitializeLives();

    void InitializeAmmo();

    void ShapeHandler(sf::Event event, sf::Vector2f position, string side);

    bool ShapeUpdate();

    void ChangeVelocity(sf::Event event);

    void Fire(sf::Event event);

    void ChangeAmmo();

    bool Impact(Shape *other_shape);

    void AfterImpact();

    void AfterMissileHit();

    void Died();

    void AmmoText();

    void ScoreText();

    void Draw(sf::RenderWindow &window_instance);
    
    inline const double& GetLength() const;

    sf::Vector2f& GetPosition();

    Shape* GetMissileMid(int index);

    Shape* GetMissileLeft(int index);

    Shape* GetMissileRight(int index);

    Shape* GetMissileDLeft(int index);

    Shape* GetMissileDRight(int index);

private:
    MISSILES_MODE m_mode;
    Shape* m_missile_middle[100];
    Shape* m_missile_left[100];
    Shape* m_missile_right[100];
    Shape* m_missile_d_left[100];
    Shape* m_missile_d_right[100];
    int m_index;
    int m_score;
    string m_colide;
    sf::Text m_ammo_text;
    sf::Text m_score_text;
    sf::Font m_font;
    
    int m_power;
    int m_lives;
    int m_ammo;

    Gadget* m_power_gadget;
    Gadget* m_lives_gadget[4];
};

#endif // PLANE_HPP