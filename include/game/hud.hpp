/*
** EPITECH PROJECT, 2024
** my-arcade-games
** File description:
** hud
*/

#ifndef HUD_HPP_
    #define HUD_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class All;

class Hud {
    public:
        Hud(All *all);
        void initText(All &all);
        void textDisplay(sf::RenderWindow &window);

        sf::Text scoreText;
        sf::Text roundText;
    private:
};

#endif /* !HUD_HPP_ */
