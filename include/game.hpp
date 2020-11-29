#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "Board.hpp"
#include "screen.hpp"

#define WINDOW_SIDE (900)

class Game
{
public:
    enum PLAYING_MODE
    {
        START = 0,
        PLAYING,
        PAUSE,
        END
    };

    Game();

    ~Game()
    {}
    
    void Run();

    void EventHandler(sf::Event event);

    bool Update();

    inline void DrawGame()
    {
        m_main_board.DrawBoard(m_main_window);
    }

private:
    Board m_main_board;
    sf::RenderWindow m_main_window;
    Screen* m_open_screen;
    Screen* m_pause_screen;
    Screen* m_end_screen;
    PLAYING_MODE m_toggle;
};

#endif // GAME_HPP