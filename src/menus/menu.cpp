#include "menus.hpp"
#include "all.hpp"

Menu::Menu(sf::RenderWindow &window) :
    window(window)
{}

void Menu::manageMenusEvent(All &all, sf::Event event)
{
    while (all.window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            if (all.screen_id != mainMenu)
                all.screen_id = mainMenu;
            else
                window.close();
        }
        if (event.type != sf::Event::MouseButtonReleased &&
            event.type == sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left) {
            for (Buttons &button : buttonsList)
                button.isClicked(all.colors);
        }
        if (event.type == sf::Event::MouseButtonReleased &&
            event.type != sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left) {
            for (Buttons &button : buttonsList) {
                if (button.state == mouseClicked) {
                    button.onClick(&all);
                    if (button.stayClickable == 1)
                        button.state = isNone;
                }
            }
        }
    }
}

void Menu::updateMenus(Colors colors)
{
    for (Buttons &button : buttonsList) {
        if (button.state == mouseClicked)
            continue;
        button.isHover(colors, window);
    }
}

void Menu::displayMenus(void)
{
    for (Buttons &button : buttonsList)
        button.displayButtons(window);
}
