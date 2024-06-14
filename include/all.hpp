#ifndef ALL_HPP_
    #define ALL_HPP_
    #include "game.hpp"
    #include "menus.hpp"
    #include "enum.hpp"
    #include "colors.hpp"
    #include "settings.hpp"
    #include <vector>
    #include <string>
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class All {
    public:
        All(void);
        void loop(void);
        void manageWindow(void);
        void updateThemeColors(void);

        Colors colors;
        Settings settings;
        Game game;
        Menus menus;
        sf::RenderWindow window;
        sf::Event event;
        sf::Font font;
        sf::Sprite logo_sprite;
        sf::Texture logo_texture;
        enum screens screen_id = mainMenu;
    private:
};

#endif /* !ALL_HPP_ */
