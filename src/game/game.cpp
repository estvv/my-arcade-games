#include "game.hpp"

Game::Game(sf::RenderWindow &window) :
    window(window),
    arena(sf::Vector2f(796, 758)),
    font(),
    score_txt("SCORE : 0", font, 30),
    round_txt("ROUND : 1", font, 30),
    score(0),
    round(0)
{
    arena.setOutlineThickness(2);
    arena.setOutlineColor(sf::Color::Green);
    arena.setPosition(sf::Vector2f(2, 40));
    arena.setFillColor(sf::Color::Black);
    score_txt.setPosition(sf::Vector2f(0, 0));
    round_txt.setPosition(sf::Vector2f(600, 0));
    if (not font.loadFromFile("./assets/pixel.ttf"))
        exit(84);
    score_txt.setFont(font);
    round_txt.setFont(font);
}

void Game::manageGameEvent(sf::Event event, enum screens &screen_id)
{
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed and event.type != sf::Event::KeyReleased) {
            // Check user input
            if (event.key.code == sf::Keyboard::Escape) {
                screen_id = mainMenu;
                snake.head->rect.setPosition(sf::Vector2f(400, 400));
            }
            if (event.key.code == sf::Keyboard::Z or event.key.code == sf::Keyboard::Up)
                snake.head->moove = NORTH;
            if (event.key.code == sf::Keyboard::S or event.key.code == sf::Keyboard::Down)
                snake.head->moove = SOUTH;
            if (event.key.code == sf::Keyboard::Q or event.key.code == sf::Keyboard::Left)
                snake.head->moove = WEST;
            if (event.key.code == sf::Keyboard::D or event.key.code == sf::Keyboard::Right)
                snake.head->moove = EAST;
        }
    }
}

// Game update
void Game::update()
{
    mooveSnake();
    endOfGame();
    appelEating();
}

// Mooving snake with Snake logic
void Game::mooveSnake(void)
{
    Node *node(snake.head->next);
    sf::Vector2f rect_pos(snake.head->rect.getPosition());
    sf::Vector2f body_pos;
    sf::Time time;

    // Clock to moove the snake each 0.9 second
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
void Game::endOfGame()
{
    Node *node(snake.head->next);
    sf::Vector2f head_pos(snake.head->rect.getPosition());

    // If the snake's head is out of the arena
    if (head_pos.x < 0 || head_pos.x > 800 || head_pos.y < 40 || head_pos.y > 800)
        window.close();
    while (node) {
        if (node->rect.getPosition() == head_pos)
            window.close();
        node = node->next;
    }
}

// Snake's head is on an apple
void Game::appelEating(void)
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
        snake.addBody();
    }
}

// Display game
void Game::displayGame()
{
    Node *node(snake.head);

    window.clear(sf::Color::Black);
    window.draw(arena);
    window.draw(score_txt);
    window.draw(round_txt);
    window.draw(apple.apple);
    while (node) {
        window.draw(node->rect);
        node = node->next;
    }
    window.display();
}
