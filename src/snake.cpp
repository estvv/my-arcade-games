#include "snake.hpp"

Node::Node(sf::RectangleShape rect) : rect(rect), next(nullptr) {}

linkedSnake::linkedSnake(sf::RectangleShape rect) : head(nullptr)
{
    head = new Node(rect);
    head->rect.setSize(sf::Vector2f(20, 20));
    head->rect.setOutlineColor(sf::Color::Cyan);
    head->rect.setFillColor(sf::Color::Cyan);
    head->rect.setOutlineThickness(2);
    head->rect.setPosition(390, 390);
}

Snake::Snake(void) : body(nullptr), moove(SOUTH)
{
    sf::RectangleShape rect(sf::Vector2f(200, 200));

    body = new linkedSnake(rect);
}

void linkedSnake::insertRect(sf::RectangleShape rect, sf::Color color) {
    Node *tmp = head;

    while (tmp->next) tmp = tmp->next;
    tmp->next = new Node(rect);
    tmp->next->rect.setSize(sf::Vector2f(100, 50));
    tmp->next->rect.setOutlineColor(color);
    tmp->next->rect.setOutlineThickness(5);
    tmp->next->rect.setPosition(10, 20);
}
