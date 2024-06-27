#include "all.hpp"
#include <iostream>

enum screens screen_id = mainMenu;

All::All(void) :
    colors(),
    assets(),
    game(this, colors, window),
    menus(this, window),
    window(sf::VideoMode(800, 800), "my-snake", sf::Style::Default)
{
    window.setPosition(sf::Vector2i(560, 100));
    window.setSize(sf::Vector2u(800, 800));
}

void All::updateThemeColors(void)
{
    menus.updateMenusColors(colors.menusColors);
    game.updateGameColors(colors.menusColors);
    game.snakeGame.updateSnakeColors(colors.snakeColors);
}

void All::manageScreens(void)
{
    window.clear(colors.menusColors.mainColor);
    if (screen_id == snakePlayScreen or screen_id == breakoutPlayScreen) {
        game.gamesEvents(*this);
        game.gamesUpdates(*this);
        game.gamesDisplay();
    } else {
        menus.menusList.at(screen_id).updateMenus(colors);
        menus.menusList.at(screen_id).displayMenus();
        menus.menusList.at(screen_id).manageMenusEvent(*this);
    }
    assets.displayImages(*this);
    window.display();
}

void All::gameLoop(void)
{
    while (window.isOpen())
        manageScreens();
}
