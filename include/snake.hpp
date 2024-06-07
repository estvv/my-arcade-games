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
        Node(sf::RectangleShape rect);

        sf::RectangleShape rect;
        Node *next;
    private:
};

class linkedSnake {
    public:
        linkedSnake(sf::RectangleShape rect);
        void insertRect(sf::RectangleShape rect, sf::Color color);

        Node *head;
    private:
};

class Snake {
    public:
        Snake(void);

        linkedSnake *body;
        enum dir moove;
        unsigned int x;
        unsigned int y;
    private:
};

#endif /* !SNAKE_HPP_ */
