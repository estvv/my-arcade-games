#ifndef SETTINGS_HPP_
    #define SETTINGS_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class Settings {
    public:
        Settings(void);
        sf::Keyboard::Key upInput = sf::Keyboard::Z;
        sf::Keyboard::Key downInput = sf::Keyboard::S;
        sf::Keyboard::Key leftInput = sf::Keyboard::Q;
        sf::Keyboard::Key rightInput = sf::Keyboard::D;
        sf::Keyboard::Key pauseInput = sf::Keyboard::Space;
        unsigned int masterVolume = 50;
        unsigned int musicVolume = 50;
        unsigned int soundVolume = 50;
    private:
};

#endif /* !SETTINGS_HPP_ */
