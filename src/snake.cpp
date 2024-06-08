#include "snake.hpp"

Node::Node(sf::RectangleShape rect) : rect(rect), next(nullptr) {}

linkedSnake::linkedSnake(sf::RectangleShape rect) : head(nullptr)
{
    head = new Node(rect);
    head->rect.setFillColor(sf::Color::Cyan);
    head->rect.setPosition(400, 400);
    head->moove = SOUTH;
}

Snake::Snake(void) : body(nullptr)
{
    sf::RectangleShape rect(sf::Vector2f(20, 20));

    body = new linkedSnake(rect);
}

void linkedSnake::insertRect(sf::RectangleShape rect, sf::Color color) {
    Node *tmp = head;

    while (tmp->next) tmp = tmp->next;
    tmp->next = new Node(rect);
    tmp->next->rect.setPosition(20, 20);
}
