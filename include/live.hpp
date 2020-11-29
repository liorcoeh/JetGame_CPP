#ifndef LIVE_HPP
#define LIVE_HPP

#include <SFML/Graphics.hpp>

#include "gadget.hpp"

class Live : public Gadget
{
public:
    Live(float window_side, float space, float pos_x, float pos_y);

    ~Live()
    {}

    //void Update(int lives);

    void Draw(sf::RenderWindow &window_instance);

private:

};

#endif // LIVE_HPP