#ifndef BUTTONS_HPP_
    #define BUTTONS_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include "enum.hpp"
    #include "colors.hpp"
    #include "sound.hpp"

class Assets;
class All;
class toggledButtons;

typedef void (*actionButtonFunc)(All &);
typedef void (*toggledButtonFunc)(All &, toggledButtons &);

void noneAction(UN All &all);
void goToMainMenu(All &all);
void goToChoosingSnakeGameMenu(All &all);
void goToChoosingBreakoutGameMenu(All &all);
void goToChoosingBubbleShooterGameMenu(All &all);
void goToSnakeGameScreen(All &all);
void goToBreakoutGameScreen(All &all);
void goToBubbleShooterGameScreen(All &all);
void goToFirstSettingsMenu(All &all);
void goToSecondSettingsMenu(All &all);
void goToLeaderboardMenu(All &all);
void goToHelpMenu(All &all);
void goToExit(All &all);
void masterVolumeUp(All &all);
void masterVolumeDown(All &all);
void soundVolumeUp(All &all);
void soundVolumeDown(All &all);
void musicVolumeUp(All &all);
void musicVolumeDown(All &all);

void noneToggled(UN All &all, UN toggledButtons &button);
void resetTheme(All &all, toggledButtons &button);
void setLightBlueTheme(All &all, toggledButtons &button);
void setPinkTheme(All &all, toggledButtons &button);
void setRedAndYellowTheme(All &all, toggledButtons &button);
void setRainbowTheme(All &all, UN toggledButtons &button);

void upInputKey(All &all, toggledButtons &button);
void downInputKey(All &all, toggledButtons &button);
void rightInputKey(All &all, toggledButtons &button);
void leftInputKey(All &all, toggledButtons &button);

class toggledButtons {
    public:
        toggledButtons(All &all, const std::string &txt, sf::Vector2f size, sf::Vector2f new_pos, toggledButtonFunc clickedFunction, toggledButtonFunc inputKeyFunction, sf::Color background);
        void displayButtons(sf::RenderWindow &window);
        void isHover(MenusColors menusColors, sf::RenderWindow &window);
        void isClicked(MenusColors menusColors);
        void onClick(All *all);
        void onInputKey(All *all);

        sf::RectangleShape button_rect;
        sf::Text button_text;
        toggledButtonFunc clickedFunction;
        toggledButtonFunc inputKeyFunction;
        Sound *mouseHoverSound;
        Sound *mouseInputSound;
        Sound *mouseClickSound;
        buttonState state;
    private:
};

class actionButtons {
    public:
        actionButtons(All &all, const std::string &txt, sf::Vector2f size, sf::Vector2f new_pos, actionButtonFunc func);
        void displayButtons(sf::RenderWindow &window);
        void isHover(MenusColors menusColors, sf::RenderWindow &window);
        void isClicked(MenusColors menusColors);
        void onClick(All *all);

        sf::RectangleShape button_rect;
        sf::Text button_text;
        actionButtonFunc func;
        Sound *mouseHoverSound;
        Sound *mouseClickSound;
        buttonState state;
    private:
};

class Buttons {
    public:
        Buttons(All &all, const std::string &txt, sf::Vector2f size, sf::Vector2f new_pos);
        void isHover(MenusColors menusColors, sf::RenderWindow &window);
        void displayButtons(sf::RenderWindow &window);

        sf::RectangleShape button_rect;
        sf::Text button_text;
        Sound *mouseHoverSound;
        buttonState state;
    private:
};

#endif /* !BUTTONS_HPP_ */
