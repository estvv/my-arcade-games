#include "all.hpp"
#include <iostream>

enum screens screen_id = mainMenu;

All::All(void) :
    colors(),
    assets(),
    game(colors, window),
    menus(this, window),
    window(sf::VideoMode(800, 800), "my-snake", sf::Style::Default)
{
    window.setPosition(sf::Vector2i(560, 100));
    window.setSize(sf::Vector2u(800, 800));
}

void All::updateThemeColors(void)
{
    Node *node = game.snake.head->next;

    for (Menu &menu : menus.menusList) {
        for (actionButtons &button : menu.actionButtonsList) {
            button.button_rect.setOutlineColor(colors.button);
            button.button_text.setFillColor(colors.buttonText);
        }
        for (toggledButtons &button : menu.toggledButtonsList) {
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
        game.manageGameEvent(*this);
        game.update(*this);
        game.displayGame();
    } else {
        menus.menusList.at(screen_id).updateMenus(colors);
        menus.menusList.at(screen_id).displayMenus();
        menus.menusList.at(screen_id).manageMenusEvent(*this);
    }
    assets.displayImages(*this);
    window.display();
}

void All::loop(void)
{
    while (window.isOpen())
        manageWindow();
}
