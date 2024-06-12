#include "all.hpp"
#include <iostream>

enum screens screen_id = mainMenu;

All::All(void) :
    masterVolume(50),
    soundVolume(50),
    musicVolume(50),
    screen_id(mainMenu),
    colors(),
    game(colors, window),
    menus(this, window),
    window(sf::VideoMode(800, 800), "my-snake", sf::Style::Default)
{
    if (!font.loadFromFile("assets/font/pixel.ttf")) {
        std::cerr << "Problem with pixel.ttf." << std::endl;
        exit(84);
    }
    window.setPosition(sf::Vector2i(560, 100));
    window.setSize(sf::Vector2u(800, 800));
    if (not logo_texture.loadFromFile("./assets/image/snake.png")) {
        std::cerr << "Problem with snake.png." << std::endl;
        exit(84);
    }
    logo_sprite.setTexture(logo_texture);
    logo_sprite.setOrigin(sf::Vector2f(0, 0));
    logo_sprite.setPosition(sf::Vector2f(210, -50));
    logo_sprite.setScale(sf::Vector2f(6, 6));
}

void All::updateThemeColors(void)
{
    Node *node = game.snake.head->next;

    for (Menu &menu : menus.menusList) {
        for (Buttons &button : menu.buttonsList) {
            if (button.button_text.getString().getSize() != 0)
                button.button_rect.setFillColor(colors.mainColor);
            button.button_rect.setOutlineColor(colors.button);
            button.button_text.setFillColor(colors.buttonText);
        }
    }
    game.apple.apple.setFillColor(colors.apple);
    game.snake.head->rect.setFillColor(colors.snakeHead);
    while (node) {
        node->rect.setFillColor(colors.snakeBody);
        node = node->next;
    }
    game.arena.setFillColor(colors.mainColor);
    game.arena.setOutlineColor(colors.button);
    game.round_txt.setFillColor(colors.buttonText);
    game.score_txt.setFillColor(colors.buttonText);
}

void All::manageWindow(void)
{
    window.clear(colors.mainColor);
    if (screen_id == playScreen) {
        game.manageGameEvent(event, screen_id);
        game.update(colors.snakeBody);
        game.displayGame();
    } else {
        menus.menusList.at(screen_id).updateMenus(colors);
        menus.menusList.at(screen_id).displayMenus();
        menus.menusList.at(screen_id).manageMenusEvent(*this, event);
        if (screen_id == mainMenu)
            window.draw(logo_sprite);
    }
    window.display();
}

void All::loop(void)
{
    while (window.isOpen()) {
        manageWindow();
    }
}
