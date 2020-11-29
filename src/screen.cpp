
#include <iostream>

#include "screen.hpp"

using namespace std;

Screen::Screen(float window_side, float space):
m_window_side(window_side), m_space(space)
{}

void Screen::MainHeadLine()
{
    cout << "In Screen MainHeadLine" << endl;
}

void Screen::PressTo()
{
    cout << "In Screen PressTo" << endl;
}

void Screen::Draw(sf::RenderWindow &window_instance)
{
    cout << "In Screen Draw" << endl;
    window_instance.draw(m_screen);
}