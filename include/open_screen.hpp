#ifndef OPEN_SCREEN_HPP
#define OPEN_SCREEN_HPP

#include "screen.hpp"

class OpenScreen : public Screen
{
public:
    OpenScreen(float window_side, float space);

    ~OpenScreen()
    {}

    void MainHeadLine();

    void PressTo();

    void Draw(sf::RenderWindow &window_instance);
};

#endif // OPEN_SCREEN_HPP