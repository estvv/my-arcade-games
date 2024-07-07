#ifndef MENU_COLORS_HPP_
    #define MENU_COLORS_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class MenusColors {
    public:
        MenusColors(void);

        sf::Color mainColor;
        sf::Color button;
        sf::Color buttonText;
        sf::Color buttonHover;
        sf::Color buttonClicked;
    private:
};

#endif /* !MENU_COLORS_HPP_ */
