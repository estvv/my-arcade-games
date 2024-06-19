#ifndef SETTINGS_HPP_
    #define SETTINGS_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class Settings {
    public:
        Settings(void);
        sf::Keyboard::Key up;
        sf::Keyboard::Key down;
        sf::Keyboard::Key left;
        sf::Keyboard::Key right;
        unsigned int masterVolume;
        unsigned int musicVolume;
        unsigned int soundVolume;
    private:
};

#endif /* !SETTINGS_HPP_ */
