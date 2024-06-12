#ifndef MENUS_HPP_
    #define MENUS_HPP_
    #include "buttons.hpp"
    #include "enum.hpp"
    #include "colors.hpp"
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class Menu {
    public:
        Menu(sf::RenderWindow &window);
        void manageMenusEvent(All &all, sf::Event event);
        void displayMenus(void);
        void updateMenus(Colors colors);

        std::vector<Buttons> buttonsList;
        sf::RenderWindow &window;
    private:
};

class Menus {
    public:
        Menus(All *all, sf::RenderWindow &window);
        void initMain(All &all);
        void initSettings(All &all);
        void initLeaderboard(All &all);

        std::vector<Menu> menusList;
    private:
};

#endif /* !MENUS_HPP_ */
