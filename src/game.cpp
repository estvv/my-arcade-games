#include "game.hpp"

Game::Game(void) : window(sf::VideoMode(800, 800), "my-snake", sf::Style::Default)
{
    window.setPosition(sf::Vector2i(560, 100));
}

void Game::run()
{
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
        }
    }
}

void Game::update()
{
    return;
}

void Game::winDisplay(void)
{
    Node *node(snake.body->head);

    window.clear(sf::Color::Black);
    while (node) {
        window.draw(node->rect);
        node = node->next;
    }
    window.display();
}
