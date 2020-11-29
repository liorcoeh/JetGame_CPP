
#include <iostream>

#include "game.hpp"
#include "open_screen.hpp"
#include "pause_screen.hpp"
#include "end_screen.hpp"

using namespace std;

Game::Game(): m_main_board(Board(WINDOW_SIDE)),
    m_main_window(sf::VideoMode(WINDOW_SIDE, WINDOW_SIDE), "GAME"), m_toggle(START)
{}

void Game::Run()
{
    m_open_screen = new OpenScreen(WINDOW_SIDE, (WINDOW_SIDE / 10) / 2);
    m_pause_screen = new PauseScreen(WINDOW_SIDE, (WINDOW_SIDE / 10) / 2);
    m_end_screen = new EndScreen(WINDOW_SIDE, (WINDOW_SIDE / 10) / 2);

    sf::Event event;
    sf::Clock clock;;

    while (m_main_window.isOpen())
    {
        while (m_main_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_main_window.close();
            }

            if (START == m_toggle)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    m_toggle = PLAYING;
                }
            }

            else if (PLAYING == m_toggle && event.key.code == sf::Keyboard::Escape)
            {
                m_toggle = PAUSE;
            }

            else if (PAUSE == m_toggle)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    m_toggle = PLAYING;
                }
            }

            else if (END == m_toggle)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    m_main_window.close();
                }
            }

            else if (PLAYING == m_toggle)
            {
                EventHandler(event);
            }
        }


        if (PLAYING == m_toggle)
        {
            if (clock.getElapsedTime().asSeconds() > (1.0 / 30.0))
            {
                clock.restart();
                if (false == Update())
                {
                    m_toggle = END;
                }
            }
        }

        m_main_window.clear();

        DrawGame();

        if (START == m_toggle)
        {
            m_open_screen->Draw(m_main_window);
        }

        if (PAUSE == m_toggle)
        {
            m_pause_screen->Draw(m_main_window);
        }

        if (END == m_toggle)
        {
            m_end_screen->Draw(m_main_window);
        }
                
        m_main_window.display();
    }
}

void Game::EventHandler(sf::Event event)
{
    m_main_board.BoardHandler(event);
}

bool Game::Update()
{
    if (false == m_main_board.BoardUpdate())
    {
        return (false);
    }

    return (true);
}

    