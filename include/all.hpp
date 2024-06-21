#ifndef ALL_HPP_
    #define ALL_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include "game.hpp"
    #include "menus.hpp"
    #include "enum.hpp"
    #include "colors.hpp"
    #include "settings.hpp"
    #include "assets.hpp"

class All {
    public:
        All(void);
        void loop(void);
        void manageWindow(void);
        void updateThemeColors(void);

        Colors colors;
        Settings settings;
        Assets assets;
        Game game;
        Menus menus;
        sf::RenderWindow window;
        sf::Event event;
        enum screens screen_id = mainMenu;
    private:
};

#endif /* !ALL_HPP_ */
