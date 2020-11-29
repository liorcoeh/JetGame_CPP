
#include <iostream>

#include "gadget.hpp"

Gadget::Gadget(float window_side, float space): m_max_side(window_side), m_space(space)
{}


void Gadget::Update(int num)
{
    (void)num;
    std::cout << "In Gadget Update" << std::endl;
}

void Gadget::Draw(sf::RenderWindow &window_instance)
{
    (void)window_instance;
    std::cout << "In Gadget Draw" << std::endl;
}