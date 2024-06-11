#ifndef ALL_HPP_
    #define ALL_HPP_
    #include "game.hpp"
    #include "menus.hpp"
    #include "enum.hpp"
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
        void initMenus(void);
        void initMain(void);
        void initSettings(void);

        Game game;
        std::vector<Menus> menusList;
        sf::RenderWindow window;
        sf::Event event;
        sf::Font font;
        sf::Sprite logo_sprite;
        sf::Texture logo_texture;
        enum screens screen_id = mainMenu;
        unsigned int masterVolume;
        unsigned int musicVolume;
        unsigned int soundVolume;
    private:
};

#endif /* !ALL_HPP_ */
