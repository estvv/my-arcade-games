#include "buttons.hpp"
#include "all.hpp"
#include <iostream>

Buttons::Buttons(const std::string &txt, sf::Vector2f size, sf::Vector2f new_pos, buttonFunc func, sf::Font &font) :
    func(func)
{
    button_rect = sf::RectangleShape(size);
    button_rect.setOutlineThickness(2);
    button_rect.setOutlineColor(sf::Color::Green);
    button_rect.setFillColor(sf::Color::Black);
    button_rect.setPosition(new_pos);
    button_text.setString(txt);
    button_text.setCharacterSize(30);
    button_text.setPosition(
        new_pos.x + (button_rect.getSize().x / 2) - (txt.length() * 10),
        new_pos.y + 5
    );
    button_text.setFont(font);
    if (txt == "EXIT")
        button_text.setFillColor(sf::Color(200, 0, 0));
}

void Buttons::isHover(sf::RenderWindow &window)
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    sf::FloatRect rect_pos;

    rect_pos = button_rect.getGlobalBounds();
    if (rect_pos.contains(mouse_pos.x, mouse_pos.y))
        button_rect.setFillColor(sf::Color(0, 150, 0, 255));
    else
        button_rect.setFillColor(sf::Color::Black);
}

void Buttons::isClicked(sf::RenderWindow &window)
{
    if (isMouseOnButton(window))
        button_rect.setFillColor(sf::Color(0, 100, 0, 255));
    else
        button_rect.setFillColor(sf::Color::Black);
}

bool Buttons::isMouseOnButton(sf::RenderWindow &window)
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    sf::FloatRect rect_pos = button_rect.getGlobalBounds();
    return rect_pos.contains(sf::Vector2f(mouse_pos.x, mouse_pos.y));
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

void playButtonFunction(All &all)
{
    all.screen_id = playScreen;
}

void settingsButtonFunction(All &all)
{
    all.screen_id = settingsMenu;
}

void leaderButtonFunction(All &all)
{
    all.screen_id = leaderboardMenu;
}

void helpButtonFunction(All &all)
{
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
        all.menusList.at(1).buttonsList.at(2).button_text.setString(std::to_string(all.masterVolume));
    }
}

void masterVolumeDown(All &all)
{
    if (all.masterVolume != 0) {
        all.masterVolume -= 10;
        all.menusList.at(1).buttonsList.at(2).button_text.setString(std::to_string(all.masterVolume));
    }
}

void musicVolumeUp(All &all)
{
    if (all.musicVolume != 100) {
        all.musicVolume += 10;
        all.menusList.at(1).buttonsList.at(6).button_text.setString(std::to_string(all.musicVolume));
    }
}

void musicVolumeDown(All &all)
{
    if (all.musicVolume != 0) {
        all.musicVolume -= 10;
        all.menusList.at(1).buttonsList.at(6).button_text.setString(std::to_string(all.musicVolume));
    }
}

void soundVolumeUp(All &all)
{
    if (all.soundVolume != 100) {
        all.soundVolume += 10;
        all.menusList.at(1).buttonsList.at(10).button_text.setString(std::to_string(all.soundVolume));
    }
}

void soundVolumeDown(All &all)
{
    if (all.soundVolume != 0) {
        all.soundVolume -= 10;
        all.menusList.at(1).buttonsList.at(10).button_text.setString(std::to_string(all.soundVolume));
    }
}

void none(All &all)
{
    return;
}
