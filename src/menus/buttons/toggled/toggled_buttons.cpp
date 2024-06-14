#include "buttons.hpp"
#include "all.hpp"
#include <iostream>

toggledButtons::toggledButtons(All &all, const std::string &txt, sf::Vector2f size, sf::Vector2f new_pos, toggledButtonFunc clickedFunction, toggledButtonFunc inputKeyFunction, sf::Color background) :
    state(isNone),
    clickedFunction(clickedFunction),
    inputKeyFunction(inputKeyFunction)
{
    button_rect = sf::RectangleShape(size);
    button_rect.setOutlineThickness(2);
    button_rect.setFillColor(background);
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

void toggledButtons::isHover(Colors colors, sf::RenderWindow &window)
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

void toggledButtons::isClicked(Colors colors)
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

void toggledButtons::onClick(All *all)
{
    clickedFunction(*all, *this);
}

void toggledButtons::onInputKey(All *all)
{
    inputKeyFunction(*all, *this);
}

void toggledButtons::displayButtons(sf::RenderWindow &window)
{
    window.draw(button_rect);
    window.draw(button_text);
}
