#ifndef POWER_HPP
#define POWER_HPP

#include <SFML/Graphics.hpp>

#include "gadget.hpp"

class Power : public Gadget
{
public:
    Power(float window_side, float space);

    ~Power()
    {}

    void Update(int power);

    void Draw(sf::RenderWindow &window_instance);

private:

};

#endif // POWER_HPP