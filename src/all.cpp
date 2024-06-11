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
    initMenus();
}

void All::initMenus(void)
{
    menusList.push_back(Menus(window, this));
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
    menusList.at(0).buttonsList.push_back(Buttons("SETTINGS", sf::Vector2f(400, 50), sf::Vector2f(200, 400), goToFirstSettingsMenu, font));
    menusList.at(0).buttonsList.push_back(Buttons("LEADERBOARD", sf::Vector2f(400, 50), sf::Vector2f(200, 500), leaderButtonFunction, font));
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
    menusList.at(1).buttonsList.push_back(Buttons("NEXT", sf::Vector2f(100, 50), sf::Vector2f(690, 740), goToSecondSettingsMenu, font));
    menusList.at(2).buttonsList.push_back(Buttons("PREV", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToFirstSettingsMenu, font));
    menusList.at(2).buttonsList.push_back(Buttons("Z", sf::Vector2f(50, 50), sf::Vector2f(50, 50), none, font));
    menusList.at(2).buttonsList.push_back(Buttons("Q", sf::Vector2f(50, 50), sf::Vector2f(50, 110), none, font));
    menusList.at(2).buttonsList.push_back(Buttons("S", sf::Vector2f(50, 50), sf::Vector2f(50, 170), none, font));
    menusList.at(2).buttonsList.push_back(Buttons("D", sf::Vector2f(50, 50), sf::Vector2f(50, 230), none, font));
    menusList.at(2).buttonsList.push_back(Buttons("SPACE", sf::Vector2f(170, 50), sf::Vector2f(50, 290), none, font));
}

void All::manageWindow(void)
{
    window.clear(sf::Color::Black);
    if (screen_id == playScreen) {
        game.manageGameEvent(event, screen_id);
        game.update();
        game.displayGame();
    } else {
        menusList.at(screen_id).updateMenus();
        menusList.at(screen_id).displayMenus();
        menusList.at(screen_id).manageMenusEvent(this, event);
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
