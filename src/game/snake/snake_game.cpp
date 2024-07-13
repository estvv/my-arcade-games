#include "snake_game.hpp"
#include "all.hpp"
#include <iostream>

using namespace std;

SnakeGame::SnakeGame(SnakeColors snakeColors) :
    arena(sf::Vector2f(600, 600), sf::Vector2f(100, 180)),
    snake(snakeColors.snakeHead),
    apple(arena, snakeColors.apple)
{
}

void SnakeGame::gameEvent(All &all)
{
    while (all.window.pollEvent(all.event)) {
        if (all.event.type == sf::Event::Closed)
            all.window.close();
        if (all.event.type == sf::Event::KeyPressed and all.event.type != sf::Event::KeyReleased) {
            // Check user input
            if (all.event.key.code == sf::Keyboard::Escape) all.screen_id = pauseMenu;
            if (all.event.key.code == all.settings.upInput or all.event.key.code == sf::Keyboard::Up) snake.head->moove = NORTH;
            if (all.event.key.code == all.settings.downInput or all.event.key.code == sf::Keyboard::Down) snake.head->moove = SOUTH;
            if (all.event.key.code == all.settings.leftInput or all.event.key.code == sf::Keyboard::Left) snake.head->moove = WEST;
            if (all.event.key.code == all.settings.rightInput or all.event.key.code == sf::Keyboard::Right) snake.head->moove = EAST;
        }
    }
}

// Game update
void SnakeGame::gameUpdate(All &all)
{
    mooveSnake(all);
    endOfGame(all);
    appelEating(all);
}

// Mooving snake with Snake logic
void SnakeGame::mooveSnake(All &all)
{
    sf::Vector2f rect_pos(snake.head->snakeCell.cell.getPosition());
    sf::Vector2f body_pos;
    sf::Time time;

    // Clock to moove the snake each 0.90 second
    time = all.game.clock.getElapsedTime();
    if (time.asSeconds() < 0.1)
        return;
    if (snake.head->next) {
        body_pos = snake.head->next->snakeCell.cell.getPosition();
        if (snake.head->moove == SOUTH and sf::Vector2f(rect_pos.x, rect_pos.y + 20) == body_pos) snake.head->moove = NORTH;
        if (snake.head->moove == NORTH and sf::Vector2f(rect_pos.x, rect_pos.y - 20) == body_pos) snake.head->moove = SOUTH;
        if (snake.head->moove == EAST and sf::Vector2f(rect_pos.x + 20, rect_pos.y) == body_pos) snake.head->moove = WEST;
        if (snake.head->moove == WEST and sf::Vector2f(rect_pos.x - 20, rect_pos.y) == body_pos) snake.head->moove = EAST;
    }
    snake.updateBody();
    if (snake.head->moove == SOUTH) snake.mooveSnake(0, 20);
    if (snake.head->moove == NORTH) snake.mooveSnake(0, -20);
    if (snake.head->moove == EAST) snake.mooveSnake(20, 0);
    if (snake.head->moove == WEST) snake.mooveSnake(-20, 0);
    all.game.clock.restart();
}

// Check if snake's head hit something
void SnakeGame::endOfGame(All &all)
{
    Node *node(snake.head->next);
    sf::Vector2f head_pos(snake.head->snakeCell.cell.getPosition());

    // If the snake's head is out of the arena
    if (head_pos.x < 100 or head_pos.x >= 700 or head_pos.y < 180 or head_pos.y >= 780)
        all.screen_id = deadMenu;
    while (node) {
        if (node->snakeCell.cell.getPosition() == head_pos)
            all.screen_id = deadMenu;
        node = node->next;
    }
    if (all.screen_id == deadMenu)
        all.assets.sounds.at(SOUND_DEATH).sound.play();
}

// Snake's head is on an apple
void SnakeGame::appelEating(All &all)
{
    Node *node(snake.head);
    sf::Vector2f snake_pos(snake.head->snakeCell.cell.getPosition());
    sf::Vector2f apple_pos(apple.appleCell.cell.getPosition());

    if (snake_pos == apple_pos) {
        apple.putAppleToRandomPlace(arena);
        apple_pos = apple.appleCell.cell.getPosition();
        // Check if apple is not on a snake node
        while (node) {
            // Reset apple position
            if (snake_pos == apple_pos) {
                apple.putAppleToRandomPlace(arena);
                node = snake.head;
            } else {
                node = node->next;
            }
        }
        all.game.score = all.game.score + 1 + all.game.round;
        all.game.hud.scoreText.setString("SCORE : " + to_string(all.game.score));
        all.menus.menusList.at(pauseMenu).buttonsList.at(1).button_text.setString(to_string(all.game.score));
        all.menus.menusList.at(deadMenu).buttonsList.at(1).button_text.setString(to_string(all.game.score));
        all.assets.sounds.at(SOUND_APPLE).sound.play();
        snake.addBody(all.colors.snakeColors.snakeBody);
    }
}

// Display game
void SnakeGame::gameDisplay(sf::RenderWindow &window)
{
    Node *node(snake.head);

    arena.drawArena(window);
    window.draw(apple.appleCell.cell);
    while (node) {
        window.draw(node->snakeCell.cell);
        node = node->next;
    }
}

void SnakeGame::updateSnakeColors(Colors colors)
{
    Node *node = snake.head->next;

    arena.arenaCell.cell.setOutlineColor(colors.menusColors.button);
    apple.appleCell.cell.setFillColor(colors.snakeColors.apple);
    snake.head->snakeCell.cell.setFillColor(colors.snakeColors.snakeHead);
    while (node) {
        node->snakeCell.cell.setFillColor(colors.snakeColors.snakeBody);
        node = node->next;
    }
}

void SnakeGame::initSnake(void)
{
    snake.head->snakeCell.cell.setPosition(sf::Vector2f(400, 400));
    snake.head->next = nullptr;
    apple.putAppleToRandomPlace(arena);
    snake.head->moove = SOUTH;
}
