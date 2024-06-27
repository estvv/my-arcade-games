#include "manage_snake.hpp"
#include "colors.hpp"
#include "all.hpp"
#include <iostream>

SnakeGame::SnakeGame(SnakeColors snakeColors) :
    snake(snakeColors.snakeHead),
    apple(snakeColors.apple)
{
}

void SnakeGame::gameEvent(All &all)
{
    while (all.window.pollEvent(all.event)) {
        if (all.event.type == sf::Event::Closed)
            all.window.close();
        if (all.event.type == sf::Event::KeyPressed and all.event.type != sf::Event::KeyReleased) {
            // Check user input
            if (all.event.key.code == sf::Keyboard::Escape)
                all.screen_id = pauseMenu;
            if (all.event.key.code == all.settings.up or all.event.key.code == sf::Keyboard::Up)
                snake.head->moove = NORTH;
            if (all.event.key.code == all.settings.down or all.event.key.code == sf::Keyboard::Down)
                snake.head->moove = SOUTH;
            if (all.event.key.code == all.settings.left or all.event.key.code == sf::Keyboard::Left)
                snake.head->moove = WEST;
            if (all.event.key.code == all.settings.right or all.event.key.code == sf::Keyboard::Right)
                snake.head->moove = EAST;
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
    sf::Vector2f rect_pos(snake.head->rect.getPosition());
    sf::Vector2f body_pos;
    sf::Time time;

    // Clock to moove the snake each 0.90 second
    time = all.game.clock.getElapsedTime();
    if (time.asSeconds() < 0.1)
        return;
    if (snake.head->next) {
        body_pos = snake.head->next->rect.getPosition();
        if (snake.head->moove == SOUTH and sf::Vector2f(rect_pos.x, rect_pos.y + 20) == body_pos) snake.head->moove = NORTH;
        if (snake.head->moove == NORTH and sf::Vector2f(rect_pos.x, rect_pos.y - 20) == body_pos) snake.head->moove = SOUTH;
        if (snake.head->moove == EAST and sf::Vector2f(rect_pos.x + 20, rect_pos.y) == body_pos) snake.head->moove = WEST;
        if (snake.head->moove == WEST and sf::Vector2f(rect_pos.x - 20, rect_pos.y) == body_pos) snake.head->moove = EAST;
    }
    snake.updateBody();
    if (snake.head->moove == SOUTH) rect_pos.y += 20;
    if (snake.head->moove == NORTH) rect_pos.y -= 20;
    if (snake.head->moove == EAST) rect_pos.x += 20;
    if (snake.head->moove == WEST) rect_pos.x -= 20;
    snake.head->rect.setPosition(rect_pos);
    all.game.clock.restart();
}

// Check if snake's head hit something
void SnakeGame::endOfGame(All &all)
{
    Node *node(snake.head->next);
    sf::Vector2f head_pos(snake.head->rect.getPosition());

    // If the snake's head is out of the arena
    if (head_pos.x < 0 or head_pos.x > 800 or head_pos.y < 40 or head_pos.y > 800)
        all.screen_id = deadMenu;
    while (node) {
        if (node->rect.getPosition() == head_pos)
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
    sf::Vector2f snake_pos(snake.head->rect.getPosition());
    sf::Vector2f apple_pos(apple.apple.getPosition());

    if (snake_pos == apple_pos) {
        srand(time(NULL));
        apple.apple.setPosition(20 * (rand() % 40), 20 * (rand() % 38) + 40);
        apple_pos = apple.apple.getPosition();
        while (node) {
            if (snake_pos == apple_pos) {
                srand(time(NULL));
                apple.apple.setPosition(20 * (rand() % 40), 20 * (rand() % 38) + 40);
                node = snake.head;
            } else {
                node = node->next;
            }
        }
        all.game.score = all.game.score + 1 + all.game.round;
        all.game.scoreText.setString("SCORE : " + std::to_string(all.game.score));
        all.menus.menusList.at(pauseMenu).buttonsList.at(1).button_text.setString(std::to_string(all.game.score));
        all.menus.menusList.at(deadMenu).buttonsList.at(1).button_text.setString(std::to_string(all.game.score));
        all.assets.sounds.at(SOUND_APPLE).sound.play();
        snake.addBody(all.colors.snakeColors.snakeBody);
    }
}

// Display game
void SnakeGame::gameDisplay(sf::RenderWindow &window)
{
    Node *node(snake.head);

    window.draw(apple.apple);
    while (node) {
        window.draw(node->rect);
        node = node->next;
    }
}

void SnakeGame::updateSnakeColors(SnakeColors snakeColors)
{
    Node *node = snake.head->next;

    apple.apple.setFillColor(snakeColors.apple);
    snake.head->rect.setFillColor(snakeColors.snakeHead);
    while (node) {
        node->rect.setFillColor(snakeColors.snakeBody);
        node = node->next;
    }
}

void SnakeGame::initSnake(void)
{
    snake.head->rect.setPosition(sf::Vector2f(400, 400));
    snake.head->next = nullptr;
    srand(time(NULL));
    apple.apple.setPosition(20 * (rand() % 40), 20 * (rand() % 38) + 40);
    snake.head->moove = SOUTH;
}
