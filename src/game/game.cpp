#include "game.hpp"
#include "colors.hpp"
#include "all.hpp"
#include <iostream>

Game::Game(All *all, Colors colors, sf::RenderWindow &window) :
    hud(all),
    snakeGame(colors.snakeColors),
    breakoutGame(),
    bubbleShooterGame(colors.objectsColors),
    window(window),
    gameState(snake)
{
}

void Game::updateGameColors(MenusColors menusColors)
{
    hud.roundText.setFillColor(menusColors.buttonText);
    hud.scoreText.setFillColor(menusColors.buttonText);
}

void Game::gamesEvents(All &all)
{
    if (gameState == snake)
        snakeGame.gameEvent(all);
    if (gameState == breakout)
        breakoutGame.gameEvent(all);
    if (gameState == bubbleShooter)
        bubbleShooterGame.gameEvent(all);
    if (gameState == tetris)
        tetrisGame.gameEvent(all);
}

// Game update
void Game::gamesUpdates(All &all)
{
    if (gameState == snake)
        snakeGame.gameUpdate(all);
    if (gameState == breakout)
        breakoutGame.gameUpdate(all);
    if (gameState == bubbleShooter)
        bubbleShooterGame.gameUpdate(all);
    if (gameState == tetris)
        tetrisGame.gameUpdate(all);
}

// Display game
void Game::gamesDisplay(void)
{
    hud.textDisplay(window);
    if (gameState == snake)
        snakeGame.gameDisplay(window);
    if (gameState == breakout)
        breakoutGame.gameDisplay(window);
    if (gameState == bubbleShooter)
        bubbleShooterGame.gameDisplay(window);
    if (gameState == tetris)
        tetrisGame.gameDisplay(window);
}
