#ifndef BUTTONS_HPP_
    #define BUTTONS_HPP_
    #include "enum.hpp"
    #include "colors.hpp"
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class All;
typedef void (*buttonFunc)(All &);

void none(All &all);
void goToMainMenu(All &all);
void playButtonFunction(All &all);
void goToFirstSettingsMenu(All &all);
void goToSecondSettingsMenu(All &all);
void leaderButtonFunction(All &all);
void helpButtonFunction(All &all);
void exitButtonFunction(All &all);
void masterVolumeUp(All &all);
void masterVolumeDown(All &all);
void soundVolumeUp(All &all);
void soundVolumeDown(All &all);
void musicVolumeUp(All &all);
void musicVolumeDown(All &all);
void resetTheme(All &all);
void setLightBlueTheme(All &all);
void setPinkTheme(All &all);
void setRedAndYellowTheme(All &all);
void setRainbowTheme(All &all);


class Buttons {
    public:
        Buttons(All &all, const std::string &txt, sf::Vector2f size, sf::Vector2f new_pos, buttonFunc func, int stayClickable);
        void displayButtons(sf::RenderWindow &window);
        void isHover(Colors colors, sf::RenderWindow &window);
        void isClicked(Colors colors);
        void onClick(All *all);

        sf::RectangleShape button_rect;
        sf::Text button_text;
        buttonFunc func;
        buttonState state;
        int stayClickable;
    private:
};

#endif /* !BUTTONS_HPP_ */
