#include "all.hpp"
#include <iostream>

enum screens screen_id = mainMenu;

All::All(void) :
    masterVolume(50),
    soundVolume(50),
    musicVolume(50),
    screen_id(mainMenu),
    game(window),
    window(sf::VideoMode(800, 800), "my-snake", sf::Style::Default)
{
    if (!font.loadFromFile("assets/pixel.ttf"))
        exit(84);
    window.setPosition(sf::Vector2i(560, 100));
    window.setSize(sf::Vector2u(800, 800));
    logo_texture.loadFromFile("./assets/snake.png");
    logo_sprite.setTexture(logo_texture);
    logo_sprite.setOrigin(sf::Vector2f(0, 0));
    logo_sprite.setPosition(sf::Vector2f(210, -50));
    logo_sprite.setScale(sf::Vector2f(6, 6));
    initMenus();
}

void All::initMenus(void)
{
    menusList.push_back(Menus(window, this));
    menusList.push_back(Menus(window, this));
    menusList.push_back(Menus(window, this));
    menusList.push_back(Menus(window, this));
    initMain();
    initSettings();
}

void All::initMain(void)
{
    menusList.at(0).buttonsList.push_back(Buttons("PLAY", sf::Vector2f(400, 50), sf::Vector2f(200, 300), playButtonFunction, font));
    menusList.at(0).buttonsList.push_back(Buttons("SETTINGS", sf::Vector2f(400, 50), sf::Vector2f(200, 400), settingsButtonFunction, font));
    menusList.at(0).buttonsList.push_back(Buttons("LEADER", sf::Vector2f(400, 50), sf::Vector2f(200, 500), leaderButtonFunction, font));
    menusList.at(0).buttonsList.push_back(Buttons("HELP", sf::Vector2f(400, 50), sf::Vector2f(200, 600), helpButtonFunction, font));
    menusList.at(0).buttonsList.push_back(Buttons("EXIT", sf::Vector2f(400, 50), sf::Vector2f(200, 700), exitButtonFunction, font));
}

void All::initSettings(void)
{
    menusList.at(1).buttonsList.push_back(Buttons("MASTER VOLUME", sf::Vector2f(400, 50), sf::Vector2f(200, 10), none, font));
    menusList.at(1).buttonsList.push_back(Buttons("-", sf::Vector2f(100, 50), sf::Vector2f(200, 80), masterVolumeDown, font));
    menusList.at(1).buttonsList.push_back(Buttons(std::to_string(masterVolume), sf::Vector2f(100, 50), sf::Vector2f(350, 80), none, font));
    menusList.at(1).buttonsList.push_back(Buttons("+", sf::Vector2f(100, 50), sf::Vector2f(500, 80), masterVolumeUp, font));
    menusList.at(1).buttonsList.push_back(Buttons("MUSIC", sf::Vector2f(400, 50), sf::Vector2f(200, 200), none, font));
    menusList.at(1).buttonsList.push_back(Buttons("-", sf::Vector2f(100, 50), sf::Vector2f(200, 270), musicVolumeDown, font));
    menusList.at(1).buttonsList.push_back(Buttons(std::to_string(musicVolume), sf::Vector2f(100, 50), sf::Vector2f(350, 270), none, font));
    menusList.at(1).buttonsList.push_back(Buttons("+", sf::Vector2f(100, 50), sf::Vector2f(500, 270), musicVolumeUp, font));
    menusList.at(1).buttonsList.push_back(Buttons("SOUNDS", sf::Vector2f(400, 50), sf::Vector2f(200, 390), none, font));
    menusList.at(1).buttonsList.push_back(Buttons("-", sf::Vector2f(100, 50), sf::Vector2f(200, 460), soundVolumeDown, font));
    menusList.at(1).buttonsList.push_back(Buttons(std::to_string(soundVolume), sf::Vector2f(100, 50), sf::Vector2f(350, 460), none, font));
    menusList.at(1).buttonsList.push_back(Buttons("+", sf::Vector2f(100, 50), sf::Vector2f(500, 460), soundVolumeUp, font));
    menusList.at(1).buttonsList.push_back(Buttons("THEME", sf::Vector2f(400, 50), sf::Vector2f(200, 580), none, font));
    menusList.at(1).buttonsList.push_back(Buttons("", sf::Vector2f(100, 50), sf::Vector2f(200, 650), none, font));
    menusList.at(1).buttonsList.push_back(Buttons("", sf::Vector2f(100, 50), sf::Vector2f(350, 650), none, font));
    menusList.at(1).buttonsList.push_back(Buttons("", sf::Vector2f(100, 50), sf::Vector2f(500, 650), none, font));
    menusList.at(1).buttonsList.push_back(Buttons("", sf::Vector2f(100, 50), sf::Vector2f(275, 720), none, font));
    menusList.at(1).buttonsList.push_back(Buttons("", sf::Vector2f(100, 50), sf::Vector2f(425, 720), none, font));
}

void All::manageWindow(void)
{
    if (screen_id == playScreen) {
        game.manageGameEvent(event, screen_id);
        game.update();
        game.displayGame();
    }
    if (screen_id == mainMenu) {
        menusList.at(0).manageMenusEvent(this, event);
        menusList.at(0).updateMenus();
        menusList.at(0).displayMenus();
        window.draw(logo_sprite);
    }
    if (screen_id == settingsMenu) {
        menusList.at(1).manageMenusEvent(this, event);
        menusList.at(1).updateMenus();
        menusList.at(1).displayMenus();
    }
    if (screen_id == leaderboardMenu) {
        menusList.at(2).manageMenusEvent(this, event);
        menusList.at(2).updateMenus();
        menusList.at(2).displayMenus();
    }
    if (screen_id == helpMenu) {
        menusList.at(3).manageMenusEvent(this, event);
        menusList.at(3).updateMenus();
        menusList.at(3).displayMenus();
    }
    window.display();
}

void All::loop(void)
{
    while (window.isOpen()) {
        manageWindow();
    }
}
