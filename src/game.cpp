#include "game.hpp"

Game::Game(void) :
    window(sf::VideoMode(800, 800), "my-snake", sf::Style::Default),
    arena(sf::Vector2f(796, 758)),
    pixel_font(),
    score_txt("SCORE : 0", pixel_font, 30),
    round_txt("ROUND : 1", pixel_font, 30),
    score(0),
    round(0)
{
    window.setPosition(sf::Vector2i(560, 100));
    arena.setOutlineThickness(2);
    arena.setOutlineColor(sf::Color::Green);
    arena.setPosition(sf::Vector2f(2, 40));
    arena.setFillColor(sf::Color::Black);
    pixel_font.loadFromFile("assets/pixel.ttf");
    score_txt.setFont(pixel_font);
    score_txt.setPosition(sf::Vector2f(0, 0));
    round_txt.setPosition(sf::Vector2f(600, 0));
    round_txt.setFont(pixel_font);
}

void Game::run()
{
    clock.restart();
    while (window.isOpen()) {
        manageEvent();
        update();
        winDisplay();
    }
}

void Game::manageEvent()
{
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed and event.type != sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Escape)
                window.close();
            // Check user input
            if (event.key.code == sf::Keyboard::Z or event.key.code == sf::Keyboard::Up)
                snake.body->head->moove = NORTH;
            if (event.key.code == sf::Keyboard::S or event.key.code == sf::Keyboard::Down)
                snake.body->head->moove = SOUTH;
            if (event.key.code == sf::Keyboard::Q or event.key.code == sf::Keyboard::Left)
                snake.body->head->moove = WEST;
            if (event.key.code == sf::Keyboard::D or event.key.code == sf::Keyboard::Right)
                snake.body->head->moove = EAST;
        }
    }
}

void Game::update()
{
    mooveSnake();
    endOfGame();
    appelEating();
}

void Game::mooveSnake(void)
{
    sf::Vector2f rect_pos(snake.body->head->rect.getPosition());
    sf::Time time;

    // Clock to moove the snake each 0.9 second
    time = clock.getElapsedTime();
    if (time.asSeconds() < 0.1)
        return;
    if (snake.body->head->moove == SOUTH)
        rect_pos.y += 20;
    if (snake.body->head->moove == NORTH)
        rect_pos.y -= 20;
    if (snake.body->head->moove == EAST)
        rect_pos.x += 20;
    if (snake.body->head->moove == WEST)
        rect_pos.x -= 20;
    snake.body->head->rect.setPosition(rect_pos);
    clock.restart();
}

void Game::endOfGame(void)
{
    sf::Vector2f rect_pos(snake.body->head->rect.getPosition());
    sf::FloatRect arena_pos(arena.getLocalBounds());

    // If the snake's head is out of the arena
    if (rect_pos.x < 0 || rect_pos.x > 800 || rect_pos.y < 40 || rect_pos.y > 800)
        window.close();
}

void Game::appelEating(void)
{
    Node *node(snake.body->head);
    sf::Vector2f snake_pos(snake.body->head->rect.getPosition());
    sf::Vector2f apple_pos(apple.apple.getPosition());

    if (snake_pos == apple_pos) {
        srand(time(NULL));
        apple.apple.setPosition(20 * (rand() % 40), 20 * (rand() % 38) + 40);
        apple_pos = apple.apple.getPosition();
        while (node) {
            if (snake_pos == apple_pos) {
                srand(time(NULL));
                apple.apple.setPosition(20 * (rand() % 40), 20 * (rand() % 38) + 40);
                node = snake.body->head;
            } else {
                node = node->next;
            }
        }
        score = score + 1 + round;
        score_txt.setString("SCORE : " + std::to_string(score));
    }
}

void Game::winDisplay(void)
{
    Node *node(snake.body->head);

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
