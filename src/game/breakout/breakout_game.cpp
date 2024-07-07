#include "breakout_game.hpp"
#include "colors.hpp"
#include "all.hpp"
#include <iostream>

BreakoutGame::BreakoutGame(void)
{
}

void BreakoutGame::gameEvent(All &all)
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
void BreakoutGame::gameUpdate(UN All &all)
{
    return;
}

// Display game
void BreakoutGame::gameDisplay(UN sf::RenderWindow &window)
{
    return;
}

void BreakoutGame::updateBreakoutColors(UN Colors colors)
{
    return;
}

void BreakoutGame::initBreakout(void)
{
    return;
}
