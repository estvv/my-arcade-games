#include "bubble_shooter_game.hpp"
#include "colors.hpp"
#include "all.hpp"
#include <iostream>

using namespace std;

BubbleShooterGame::BubbleShooterGame(ObjectsColors colors) :
    shootingBall(colors.getRandomObjectColor(colors.ballColors), sf::Vector2f(400, 700), 13)
{
    initTargetBalls(colors);
}

void BubbleShooterGame::initTargetBalls(ObjectsColors colors)
{
    vector<Ball> row;
    int x = -25;
    int y = 45;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 23; j++) {
            x += 33;
            row.emplace_back(colors.getRandomObjectColor(colors.ballColors), sf::Vector2f(x, y), 13);
        }
        if (i % 2 != 0)
            x = -25;
        else {
            x += 33;
            row.emplace_back(colors.getRandomObjectColor(colors.ballColors), sf::Vector2f(x, y), 13);
            x = -10;
        }
        y += 35;
        targetsBalls.push_back(row);
    }
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
    window.draw(shootingBall.shape);
    for (vector vector : targetsBalls)
        for (Ball &ball : vector)
            window.draw(ball.shape);
}

void BubbleShooterGame::updateBubbleShooterColors(UN ObjectsColors colors)
{
    return;
}

void BubbleShooterGame::initBubbleShooter(void)
{
    return;
}
