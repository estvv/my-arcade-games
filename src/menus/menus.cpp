#include "menus.hpp"
#include "all.hpp"

Menus::Menus(sf::RenderWindow &window, All *all) : window(window), all(all) {}

void Menus::manageMenusEvent(All *all, sf::Event event)
{
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            if ((*all).screen_id != mainMenu)
                (*all).screen_id = mainMenu;
            else
                window.close();
        }
        if (event.type != sf::Event::MouseButtonReleased &&
            event.type == sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left) {
            for (Buttons &button : buttonsList)
                button.isClicked(all, window);
        }
        if (event.type == sf::Event::MouseButtonReleased &&
            event.type != sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left) {
            for (Buttons &button : buttonsList) {
                if (button.state == mouseClicked)
                    button.onClick(all);
            }
        }
    }
}

void Menus::updateMenus(void)
{
    for (Buttons &button : buttonsList) {
        if (button.state == mouseClicked)
            continue;
        button.isHover(window);
    }
}

void Menus::displayMenus(void)
{
    for (Buttons &button : buttonsList)
        button.displayButtons(window);
}
