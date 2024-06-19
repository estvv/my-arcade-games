#include "game.hpp"
#include "colors.hpp"
#include "all.hpp"
#include <iostream>

Game::Game(Colors colors, sf::RenderWindow &window) :
    snake(colors.snakeHead),
    apple(colors.apple),
    window(window),
    arena(sf::Vector2f(796, 758)),
    font(),
    score_txt("SCORE : 0", font, 30),
    round_txt("ROUND : 1", font, 30),
    score(0),
    round(0)
{
    arena.setOutlineThickness(2);
    arena.setOutlineColor(sf::Color(0, 240, 0));
    arena.setPosition(sf::Vector2f(2, 40));
    arena.setFillColor(colors.mainColor);
    score_txt.setPosition(sf::Vector2f(0, 0));
    round_txt.setPosition(sf::Vector2f(600, 0));
    if (not font.loadFromFile("./assets/font/pixel.ttf")) {
        std::cerr << "Problem with pixel.ttf." << std::endl;
        exit(84);
    }
    score_txt.setFont(font);
    round_txt.setFont(font);
}

void Game::manageGameEvent(All &all)
{
    while (window.pollEvent(all.event)) {
        if (all.event.type == sf::Event::Closed)
            window.close();
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
void Game::update(All &all)
{
    mooveSnake();
    endOfGame(all);
    appelEating(all);
}

// Mooving snake with Snake logic
void Game::mooveSnake(void)
{
    sf::Vector2f rect_pos(snake.head->rect.getPosition());
    sf::Vector2f body_pos;
    sf::Time time;

    // Clock to moove the snake each 0.90 second
    time = clock.getElapsedTime();
    if (time.asSeconds() < 0.1)
        return;
    if (snake.head->next) {
        body_pos = snake.head->next->rect.getPosition();
        if (snake.head->moove == SOUTH and sf::Vector2f(rect_pos.x, rect_pos.y + 20) == body_pos)
            snake.head->moove = NORTH;
        if (snake.head->moove == NORTH and sf::Vector2f(rect_pos.x, rect_pos.y - 20) == body_pos)
            snake.head->moove = SOUTH;
        if (snake.head->moove == EAST and sf::Vector2f(rect_pos.x + 20, rect_pos.y) == body_pos)
            snake.head->moove = WEST;
        if (snake.head->moove == WEST and sf::Vector2f(rect_pos.x - 20, rect_pos.y) == body_pos)
            snake.head->moove = EAST;
    }
    snake.updateBody();
    if (snake.head->moove == SOUTH) rect_pos.y += 20;
    if (snake.head->moove == NORTH) rect_pos.y -= 20;
    if (snake.head->moove == EAST) rect_pos.x += 20;
    if (snake.head->moove == WEST) rect_pos.x -= 20;
    snake.head->rect.setPosition(rect_pos);
    clock.restart();
}

// Check if snake's head hit something
void Game::endOfGame(All &all)
{
    Node *node(snake.head->next);
    sf::Vector2f head_pos(snake.head->rect.getPosition());

    // If the snake's head is out of the arena
    if (head_pos.x < 0 || head_pos.x > 800 || head_pos.y < 40 || head_pos.y > 800)
        all.screen_id = deadMenu;
    while (node) {
        if (node->rect.getPosition() == head_pos)
            all.screen_id = deadMenu;
        node = node->next;
    }
}

// Snake's head is on an apple
void Game::appelEating(All &all)
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
        score = score + 1 + round;
        score_txt.setString("SCORE : " + std::to_string(score));
        all.menus.menusList.at(pauseMenu).actionButtonsList.at(3).button_text.setString(std::to_string(all.game.score));
        all.menus.menusList.at(deadMenu).actionButtonsList.at(3).button_text.setString(std::to_string(all.game.score));
        snake.addBody(all.colors.snakeBody);
    }
}

// Display game
void Game::displayGame()
{
    Node *node(snake.head);

    window.draw(arena);
    window.draw(score_txt);
    window.draw(round_txt);
    window.draw(apple.apple);
    while (node) {
        window.draw(node->rect);
        node = node->next;
    }
}
