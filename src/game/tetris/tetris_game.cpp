#include "tetris_game.hpp"
#include "colors.hpp"
#include "all.hpp"
#include <iostream>

TetrisGame::TetrisGame(void) :
    arena(sf::Vector2f(200, 500), sf::Vector2f(300, 240)),
    blocks()
{
}

// Game event
void TetrisGame::gameEvent(All &all)
{
    while (all.window.pollEvent(all.event)) {
        if (all.event.type == sf::Event::Closed)
            all.window.close();
        if (all.event.type == sf::Event::KeyPressed and all.event.type != sf::Event::KeyReleased) {
            // Check user input
            if (all.event.key.code == sf::Keyboard::Escape) all.screen_id = pauseMenu;
            if (all.event.key.code == all.settings.upInput or all.event.key.code == sf::Keyboard::Up) blocks.updateBlockRotation();
            if (all.event.key.code == all.settings.downInput or all.event.key.code == sf::Keyboard::Down) blocks.updatePosition(0, 1);
            if (all.event.key.code == all.settings.leftInput or all.event.key.code == sf::Keyboard::Left) blocks.updatePosition(-1, 0);
            if (all.event.key.code == all.settings.rightInput or all.event.key.code == sf::Keyboard::Right) blocks.updatePosition(1, 0);
            if (all.event.key.code == sf::Keyboard::K) {
                blocks.displayBlocksArray(all.window);
            }
            if (all.event.key.code == all.settings.pauseInput or all.event.key.code == sf::Keyboard::Space) {
                if (onPause == OFF) onPause = ON;
                else onPause = OFF;
                all.game.clock.restart();
            }
        }
/*         if (all.event.type != sf::Event::MouseButtonReleased and all.event.type == sf::Event::MouseButtonPressed) {
            if (all.event.mouseButton.button == sf::Mouse::Right) currBlock.updateBlockRotation(arena);
        } */
    }
}

// Game update
void TetrisGame::gameUpdate(All &all)
{
    if (blocks.block.is_stuck) {
        blocks.block.create_Block(blocks.blocksArray);
    }
    if (all.game.clock.getElapsedTime().asSeconds() > 1 and onPause == OFF) {
        blocks.updatePosition(0, 1);
        blocks.checkCompleteLine();
        all.game.clock.restart();
    }
}

// Display game
void TetrisGame::gameDisplay(sf::RenderWindow &window)
{
    arena.drawArena(window);
    blocks.displayBlocksArray(window);
}

void TetrisGame::updateTetrisColors(Colors colors)
{
    arena.arenaCell.cell.setOutlineColor(colors.menusColors.button);
}

void TetrisGame::initTetris(void)
{
    return;
}
