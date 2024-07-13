#ifndef SNAKE_HPP_
    #define SNAKE_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <iostream>
    #include "cell.hpp"

enum dir {
    NORTH,
    SOUTH,
    EAST,
    WEST,
};

class Node {
    public:
        Node(Node *prev, sf::Vector2f pos, sf::Color color);

        enum dir moove = SOUTH;
        Cell snakeCell;
        Node *next;
        Node *prev;
    private:
};

class Snake {
    public:
        Snake(sf::Color snakeHeadColor);
        void insertNode(sf::Vector2f pos, sf::Color snakeBodyColor);
        void addBody(sf::Color snakeBodyColor);
        void updateBody(void);
        void mooveSnake(const int x, const int y);

        Node *head;
    private:
};

#endif /* !SNAKE_HPP_ */
