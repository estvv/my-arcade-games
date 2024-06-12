#include "buttons.hpp"
#include "all.hpp"
#include <iostream>

Buttons::Buttons(All &all, const std::string &txt, sf::Vector2f size, sf::Vector2f new_pos, buttonFunc func, int stayClickable) :
    stayClickable(stayClickable),
    state(isNone),
    func(func)
{
    button_rect = sf::RectangleShape(size);
    button_rect.setOutlineThickness(2);
    button_rect.setFillColor(all.colors.mainColor);
    button_rect.setOutlineColor(all.colors.button);
    button_rect.setPosition(new_pos);
    button_text.setString(txt);
    button_text.setCharacterSize(30);
    button_text.setPosition(
        new_pos.x + (button_rect.getSize().x / 2) - (txt.length() * 10),
        new_pos.y + 5
    );
    button_text.setFont(all.font);
    if (txt == "EXIT")
        button_text.setFillColor(sf::Color(200, 0, 0));
}

void Buttons::isHover(Colors colors, sf::RenderWindow &window)
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    sf::FloatRect rect_pos;

    rect_pos = button_rect.getGlobalBounds();
    if (rect_pos.contains(mouse_pos.x, mouse_pos.y)) {
        if (button_text.getString().getSize() != 0)
            button_rect.setFillColor(colors.buttonHover);
        state = mouseHover;
    } else {
        if (button_text.getString().getSize() != 0)
            button_rect.setFillColor(colors.mainColor);
        state = isNone;
    }
}

void Buttons::isClicked(Colors colors)
{
    if (state == mouseHover) {
        if (button_text.getString().getSize() != 0)
            button_rect.setFillColor(colors.buttonClicked);
        state = mouseClicked;
    } else {
        if (button_text.getString().getSize() != 0)
            button_rect.setFillColor(colors.mainColor);
        state = isNone;
    }
}

void Buttons::onClick(All *all)
{
    func(*all);
}

void Buttons::displayButtons(sf::RenderWindow &window)
{
    window.draw(button_rect);
    window.draw(button_text);
}

void goToMainMenu(All &all)
{
    for (Buttons &button : all.menus.menusList.at(all.screen_id).buttonsList)
        button.state = isNone;
    all.screen_id = mainMenu;
}

void playButtonFunction(All &all)
{
    for (Buttons &button : all.menus.menusList.at(all.screen_id).buttonsList)
        button.state = isNone;
    all.screen_id = playScreen;
}

void goToFirstSettingsMenu(All &all)
{
    for (Buttons &button : all.menus.menusList.at(all.screen_id).buttonsList)
        button.state = isNone;
    all.screen_id = settingsFirstMenu;
}

void goToSecondSettingsMenu(All &all)
{
    for (Buttons &button : all.menus.menusList.at(all.screen_id).buttonsList)
        button.state = isNone;
    all.screen_id = settingsSecondMenu;
}

void leaderButtonFunction(All &all)
{
    for (Buttons &button : all.menus.menusList.at(all.screen_id).buttonsList)
        button.state = isNone;
    all.screen_id = leaderboardMenu;
}

void helpButtonFunction(All &all)
{
    for (Buttons &button : all.menus.menusList.at(all.screen_id).buttonsList)
        button.state = isNone;
    all.screen_id = helpMenu;
}

void exitButtonFunction(All &all)
{
    all.window.close();
}

void masterVolumeUp(All &all)
{
    if (all.masterVolume != 100) {
        all.masterVolume += 10;
        all.menus.menusList.at(1).buttonsList.at(2).button_text.setString(std::to_string(all.masterVolume));
    }
}

void masterVolumeDown(All &all)
{
    if (all.masterVolume != 0) {
        all.masterVolume -= 10;
        all.menus.menusList.at(1).buttonsList.at(2).button_text.setString(std::to_string(all.masterVolume));
    }
}

void musicVolumeUp(All &all)
{
    if (all.musicVolume != 100) {
        all.musicVolume += 10;
        all.menus.menusList.at(1).buttonsList.at(6).button_text.setString(std::to_string(all.musicVolume));
    }
}

void musicVolumeDown(All &all)
{
    if (all.musicVolume != 0) {
        all.musicVolume -= 10;
        all.menus.menusList.at(1).buttonsList.at(6).button_text.setString(std::to_string(all.musicVolume));
    }
}

void soundVolumeUp(All &all)
{
    if (all.soundVolume != 100) {
        all.soundVolume += 10;
        all.menus.menusList.at(1).buttonsList.at(10).button_text.setString(std::to_string(all.soundVolume));
    }
}

void soundVolumeDown(All &all)
{
    if (all.soundVolume != 0) {
        all.soundVolume -= 10;
        all.menus.menusList.at(1).buttonsList.at(10).button_text.setString(std::to_string(all.soundVolume));
    }
}

void resetTheme(All &all)
{
    all.colors.mainColor = sf::Color::Black;
    all.colors.button = sf::Color::Green;
    all.colors.buttonText = sf::Color::White;
    all.colors.buttonHover = sf::Color(0, 150, 0);
    all.colors.buttonClicked = sf::Color(0, 100, 0);
    all.colors.snakeHead = sf::Color(0, 150, 0);
    all.colors.snakeBody = sf::Color(0, 200, 0);
    all.colors.apple = sf::Color::Red;
    all.updateThemeColors();
}

void setLightBlueTheme(All &all)
{
    all.colors.mainColor = sf::Color(204, 219, 253);
    all.colors.button = sf::Color(0, 40, 85);
    all.colors.buttonText = sf::Color(109, 118, 136);
    all.colors.buttonHover = sf::Color(183, 197, 227);
    all.colors.buttonClicked = sf::Color(146, 157, 181);
    all.colors.snakeHead = sf::Color(3, 83, 164);
    all.colors.snakeBody = sf::Color(4, 102, 200);
    all.colors.apple = sf::Color(20, 21, 25);
    all.updateThemeColors();
}

void setRedAndYellowTheme(All &all)
{
    all.colors.mainColor = sf::Color(255, 102, 102);
    all.colors.button = sf::Color(244, 232, 105);
    all.colors.buttonText = sf::Color(142, 56, 56);
    all.colors.buttonHover = sf::Color(197, 187, 84);
    all.colors.buttonClicked = sf::Color(177, 168, 75);
    all.colors.snakeHead = sf::Color(216, 202, 57);
    all.colors.snakeBody = sf::Color(241, 225, 64);
    all.colors.apple = sf::Color(255, 213, 128);
    all.updateThemeColors();
}

void setPinkTheme(All &all)
{
    all.colors.mainColor = sf::Color(255, 204, 230);
    all.colors.button = sf::Color(155, 123, 140);
    all.colors.buttonText = sf::Color(139, 110, 126);
    all.colors.buttonHover = sf::Color(222, 177, 200);
    all.colors.buttonClicked = sf::Color(125, 99, 113);
    all.colors.snakeBody = sf::Color(255, 155, 210);
    all.colors.snakeHead = sf::Color(229, 139, 189);
    all.colors.apple = sf::Color::White;
    all.updateThemeColors();
}

void setRainbowTheme(All &all)
{
    all.updateThemeColors();
}

void none(All &all)
{
    return;
}
