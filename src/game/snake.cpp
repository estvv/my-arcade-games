#include "snake.hpp"

Node::Node(Node *prev, sf::Vector2f pos,  sf::Color color) :
    rect(sf::RectangleShape(sf::Vector2f(20, 20))),
    prev(prev),
    next(nullptr)
{
    rect.setFillColor(color);
    rect.setPosition(pos);
    moove = SOUTH;
}

// Init head of the snake (Cyan square)
Snake::Snake(void) : head(nullptr)
{
    head = new Node(nullptr, sf::Vector2f(400, 400), sf::Color::Cyan);
}

// Insert a node in the linked list
void Snake::InsertNode(sf::Vector2f pos, sf::Color color)
{
    Node *curr = head;

    while (curr->next)
        curr = curr->next;
    curr->next = new Node(curr, pos, color);
    curr->next->moove = curr->moove;
}

// Add one square body of the snake
void Snake::addBody(void)
{
    Node *curr(head->next);
    sf::Vector2f new_coords;

    if (not curr) {
        new_coords = head->rect.getPosition();
        if (head->moove == SOUTH) new_coords.y -= 20;
        if (head->moove == NORTH) new_coords.y += 20;
        if (head->moove == EAST) new_coords.x -= 20;
        if (head->moove == WEST) new_coords.x += 20;
        InsertNode(new_coords, sf::Color::Magenta);
    } else {
        while (curr->next) curr = curr->next;
        new_coords = curr->prev->rect.getPosition();
        if (curr->prev->moove == SOUTH) new_coords.y -= 20;
        if (curr->prev->moove == NORTH) new_coords.y += 20;
        if (curr->prev->moove == EAST) new_coords.x -= 20;
        if (curr->prev->moove == WEST) new_coords.x += 20;
        InsertNode(new_coords, sf::Color::Magenta);
    }
}

// Update the positions of each squares of the snake's body
void Snake::updateBody(void)
{
    Node *curr(head);
    sf::Vector2f prev_coords;
    sf::Vector2f new_coords;

    while (curr->next) curr = curr->next;
    while (curr->prev) {
        prev_coords = curr->prev->rect.getPosition();
        curr->rect.setPosition(prev_coords);
        curr->moove = curr->prev->moove;
        curr = curr->prev;
    }
}
