#ifndef SNAKE_HPP_
    #define SNAKE_HPP_
    #include <iostream>
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

enum dir {
    NORTH,
    SOUTH,
    EAST,
    WEST,
};

class Node {
    public:
        Node(Node *prev, sf::Vector2f pos, sf::Color color);

        sf::RectangleShape rect;
        enum dir moove;
        Node *next;
        Node *prev;
    private:
};

class Snake {
    public:
        Snake(sf::Color snakeHeadColor);
        void InsertNode(sf::Vector2f pos, sf::Color snakeBodyColor);
        void addBody(sf::Color snakeBodyColor);
        void updateBody(void);

        Node *head;
    private:
};

#endif /* !SNAKE_HPP_ */
