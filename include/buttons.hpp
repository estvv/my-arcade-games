#ifndef BUTTONS_HPP_
    #define BUTTONS_HPP_
    #include "enum.hpp"
    #include "colors.hpp"
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class All;
class toggledButtons;
typedef void (*actionButtonFunc)(All &);
typedef void (*toggledButtonFunc)(All &, toggledButtons &);

void noneAction(All &all);
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

void noneToggled(All &all, toggledButtons &button);
void resetTheme(All &all, toggledButtons &button);
void setLightBlueTheme(All &all, toggledButtons &button);
void setPinkTheme(All &all, toggledButtons &button);
void setRedAndYellowTheme(All &all, toggledButtons &button);
void setRainbowTheme(All &all, toggledButtons &button);

void upInputKey(All &all, toggledButtons &button);
void downInputKey(All &all, toggledButtons &button);
void rightInputKey(All &all, toggledButtons &button);
void leftInputKey(All &all, toggledButtons &button);

class toggledButtons {
    public:
        toggledButtons(All &all, const std::string &txt, sf::Vector2f size, sf::Vector2f new_pos, toggledButtonFunc clickedFunction, toggledButtonFunc inputKeyFunction, sf::Color background);
        void displayButtons(sf::RenderWindow &window);
        void isHover(Colors colors, sf::RenderWindow &window);
        void isClicked(Colors colors);
        void onClick(All *all);
        void onInputKey(All *all);

        sf::RectangleShape button_rect;
        sf::Text button_text;
        toggledButtonFunc clickedFunction;
        toggledButtonFunc inputKeyFunction;
        buttonState state;
    private:
};

class actionButtons {
    public:
        actionButtons(All &all, const std::string &txt, sf::Vector2f size, sf::Vector2f new_pos, actionButtonFunc func);
        void displayButtons(sf::RenderWindow &window);
        void isHover(Colors colors, sf::RenderWindow &window);
        void isClicked(Colors colors);
        void onClick(All *all);

        sf::RectangleShape button_rect;
        sf::Text button_text;
        actionButtonFunc func;
        buttonState state;
    private:
};

#endif /* !BUTTONS_HPP_ */
