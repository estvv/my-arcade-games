#include "tetris_game.hpp"
#include "colors.hpp"
#include "all.hpp"
#include <iostream>

TetrisGame::TetrisGame(void) :
    arena(sf::Vector2f(200, 500), sf::Vector2f(300, 240))
{
}

void TetrisGame::gameEvent(All &all)
{
    while (all.window.pollEvent(all.event)) {
        if (all.event.type == sf::Event::Closed)
            all.window.close();
        if (all.event.type == sf::Event::KeyPressed and all.event.type != sf::Event::KeyReleased) {
            // Check user input
            if (all.event.key.code == sf::Keyboard::Escape)
                all.screen_id = pauseMenu;
        }
    }
}

// Game update
void TetrisGame::gameUpdate(UN All &all)
{
    return;
}

// Display game
void TetrisGame::gameDisplay(sf::RenderWindow &window)
{
    arena.drawArena(window);
}

void TetrisGame::updateTetrisColors(Colors colors)
{
    arena.arena.setOutlineColor(colors.menusColors.button);
    return;
}

void TetrisGame::initTetris(void)
{
    return;
}
