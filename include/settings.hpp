#ifndef SETTINGS_HPP_
    #define SETTINGS_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class Settings {
    public:
        Settings(void);
        sf::Keyboard::Key upInput;
        sf::Keyboard::Key downInput;
        sf::Keyboard::Key leftInput;
        sf::Keyboard::Key rightInput;
        unsigned int masterVolume;
        unsigned int musicVolume;
        unsigned int soundVolume;
    private:
};

#endif /* !SETTINGS_HPP_ */
