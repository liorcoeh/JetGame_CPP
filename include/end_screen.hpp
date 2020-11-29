#ifndef END_SCREEN_HPP
#define END_SCREEN_HPP

#include "screen.hpp"

class EndScreen : public Screen
{
public:
    EndScreen(float window_side, float space);

    ~EndScreen()
    {}

    void MainHeadLine();

    void PressTo();

    void Draw(sf::RenderWindow &window_instance);
};

#endif // END_SCREEN_HPP