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
                button.isClicked(window);
        }
        if (event.type == sf::Event::MouseButtonReleased &&
            event.type != sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left) {
            for (Buttons &button : buttonsList) {
                if (button.isMouseOnButton(window))
                    button.onClick(all);
                button.button_rect.setFillColor(sf::Color::Black);
            }
        }
    }
}

void Menus::updateMenus(void)
{
    for (Buttons &button : buttonsList) {
        if (button.button_rect.getFillColor() == sf::Color(0, 100, 0, 255))
            return;
    }
    for (Buttons &button : buttonsList)
        button.isHover(window);
}

void Menus::displayMenus(void)
{
    window.clear(sf::Color::Black);
    for (Buttons &button : buttonsList)
        button.displayButtons(window);
}
