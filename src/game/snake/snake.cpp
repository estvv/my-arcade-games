#include "snake.hpp"
#include "colors.hpp"

Node::Node(Node *prev, sf::Vector2f pos, sf::Color color) :
    snakeCell(sf::Vector2f(20, 20), pos, color, sf::Color::Transparent, 0),
    next(nullptr),
    prev(prev)
{
}

// Init head of the snake
Snake::Snake(sf::Color snakeHeadColor) : head(nullptr)
{
    head = new Node(nullptr, sf::Vector2f(400, 400), snakeHeadColor);
}

// Insert a node in the filepathed list
void Snake::insertNode(sf::Vector2f pos, sf::Color snakeBodyColor)
{
    Node *curr = head;

    while (curr->next) curr = curr->next;
    curr->next = new Node(curr, pos, snakeBodyColor);
    curr->next->moove = curr->moove;
}

// Add one square body of the snake
void Snake::addBody(sf::Color snakeBodyColor)
{
    Node *curr(head->next);
    sf::Vector2f new_coords;

    if (not curr) {
        new_coords = head->snakeCell.cell.getPosition();
        if (head->moove == SOUTH) new_coords.y -= 20;
        if (head->moove == NORTH) new_coords.y += 20;
        if (head->moove == EAST) new_coords.x -= 20;
        if (head->moove == WEST) new_coords.x += 20;
        insertNode(new_coords, snakeBodyColor);
    } else {
        while (curr->next) curr = curr->next;
        new_coords = curr->prev->snakeCell.cell.getPosition();
        if (curr->prev->moove == SOUTH) new_coords.y -= 20;
        if (curr->prev->moove == NORTH) new_coords.y += 20;
        if (curr->prev->moove == EAST) new_coords.x -= 20;
        if (curr->prev->moove == WEST) new_coords.x += 20;
        insertNode(new_coords, snakeBodyColor);
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
        prev_coords = curr->prev->snakeCell.cell.getPosition();
        curr->snakeCell.cell.setPosition(prev_coords);
        curr->moove = curr->prev->moove;
        curr = curr->prev;
    }
}

void Snake::mooveSnake(const int x, const int y)
{
    head->snakeCell.cell.move(sf::Vector2f(x, y));
}
