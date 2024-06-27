#include "manage_bubble_shooter.hpp"
#include "colors.hpp"
#include "all.hpp"
#include <iostream>

BubbleShooterGame::BubbleShooterGame(void)
{
}

void BubbleShooterGame::gameEvent(All &all)
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
void BubbleShooterGame::gameUpdate(UN All &all)
{
    return;
}

// Display game
void BubbleShooterGame::gameDisplay(UN sf::RenderWindow &window)
{
    return;
}

void BubbleShooterGame::updateBreakoutColors(UN Colors colors)
{
    return;
}

void BubbleShooterGame::initBreakout(void)
{
    return;
}
