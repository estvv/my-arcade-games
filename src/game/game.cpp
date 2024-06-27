#include "game.hpp"
#include "colors.hpp"
#include "all.hpp"
#include <iostream>

Game::Game(All *all, Colors colors, sf::RenderWindow &window) :
    snakeGame(colors.snakeColors),
    breakoutGame(),
    window(window),
    arena(sf::Vector2f(796, 758)),
    scoreText("SCORE : 0", all->assets.fonts.at(0).font, 30),
    roundText("ROUND : 1", all->assets.fonts.at(0).font, 30),
    score(0),
    round(0),
    gameState(snake)
{
    arena.setOutlineThickness(2);
    arena.setOutlineColor(sf::Color(0, 240, 0));
    arena.setPosition(sf::Vector2f(2, 40));
    arena.setFillColor(colors.menusColors.mainColor);
    scoreText.setPosition(sf::Vector2f(0, 0));
    roundText.setPosition(sf::Vector2f(600, 0));
}

void Game::updateGameColors(MenusColors menusColors)
{
    arena.setFillColor(menusColors.mainColor);
    arena.setOutlineColor(menusColors.button);
    roundText.setFillColor(menusColors.buttonText);
    scoreText.setFillColor(menusColors.buttonText);
}

void Game::gamesEvents(All &all)
{
    if (gameState == snake)
        snakeGame.gameEvent(all);
    if (gameState == breakout)
        breakoutGame.gameEvent(all);
    if (gameState == bubbleShooter)
        bubbleShooterGame.gameEvent(all);
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
}

// Display game
void Game::gamesDisplay()
{
    window.draw(arena);
    window.draw(scoreText);
    window.draw(roundText);
    if (gameState == snake)
        snakeGame.gameDisplay(window);
    if (gameState == breakout)
        breakoutGame.gameDisplay(window);
    if (gameState == bubbleShooter)
        bubbleShooterGame.gameDisplay(window);
}
