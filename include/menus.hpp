#ifndef MENUS_HPP_
    #define MENUS_HPP_
    #include "buttons.hpp"
    #include "enum.hpp"
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class Menus {
    public:
        Menus(sf::RenderWindow &window, All *all);
        void manageMenusEvent(All *all, sf::Event event);
        void displayMenus();
        void updateMenus(void);

        std::vector<Buttons> buttonsList;
        sf::RenderWindow &window;
        All *all;
    private:
};

#endif /* !MENUS_HPP_ */
