#ifndef BUTTONS_HPP_
    #define BUTTONS_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class All;
typedef void (*buttonFunc)(All &);

void none(All &all);
void playButtonFunction(All &all);
void settingsButtonFunction(All &all);
void leaderButtonFunction(All &all);
void helpButtonFunction(All &all);
void exitButtonFunction(All &all);
void masterVolumeUp(All &all);
void masterVolumeDown(All &all);
void soundVolumeUp(All &all);
void soundVolumeDown(All &all);
void musicVolumeUp(All &all);
void musicVolumeDown(All &all);

class Buttons {
    public:
        Buttons(const std::string &txt, sf::Vector2f size, sf::Vector2f new_pos, buttonFunc func, sf::Font &font);
        void displayButtons(sf::RenderWindow& window);
        void isHover(sf::RenderWindow &window);
        void isClicked(sf::RenderWindow &window);
        bool isMouseOnButton(sf::RenderWindow &window);
        void onClick(All *all);

        sf::RectangleShape button_rect;
        sf::Text button_text;
        buttonFunc func;
    private:
};

#endif /* !BUTTONS_HPP_ */
