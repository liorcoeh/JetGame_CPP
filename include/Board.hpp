#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "shapes.hpp"

class Board
{
public:
    Board()
    {}

    Board(float main_window_side);

    ~Board()
    {}

    void InitializeBoard();

    void BoardHandler(sf::Event event);

    bool BoardUpdate();

    void EnemyRestart();

    void Colisions();

    void DrawBoard(sf::RenderWindow &window_instance);

private:
    sf::RectangleShape m_board;
    float m_max_side;
    float m_space;
    Shape* m_plane;
    int m_num_of_enenmy_planes;
    sf::Clock m_clock;
    int m_restart_time;
    vector <Shape*> m_enemy;
    vector <Shape*> m_dif;
};

#endif // BOARD_HPP