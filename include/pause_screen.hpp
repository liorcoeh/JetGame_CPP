#ifndef PAUSE_SCREEN_HPP
#define PAUSE_SCREEN_HPP

#include "screen.hpp"

class PauseScreen : public Screen
{
public:
    PauseScreen(float window_side, float space);

    ~PauseScreen()
    {}

    void MainHeadLine();

    void PressTo();

    void Draw(sf::RenderWindow &window_instance);
};

#endif // PAUSE_SCREEN_HPP