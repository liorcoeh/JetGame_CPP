#ifndef GADGET_HPP
#define GADGET_HPP

#include <SFML/Graphics.hpp>

using namespace std;

class Gadget
{
public:
    Gadget()
    {}

    Gadget(float window_side, float space);

    virtual ~Gadget()
    {}

    virtual void Update(int num);

    virtual void Draw(sf::RenderWindow &window_instance);

protected:
    float m_max_side;
    float m_space;
    sf::ConvexShape m_shape;
    sf::Vector2f m_position;
    float m_length;
    int m_amount;
};

#endif // GADGET_HPP