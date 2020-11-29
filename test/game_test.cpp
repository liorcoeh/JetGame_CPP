
#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "enemy.hpp"
#include "utilities.hpp" // Clear()

using namespace std;

int main()
{
    Clear();

    Game new_game;

    new_game.Run();

    return (0);
}