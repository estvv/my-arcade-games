#ifndef SOUND_HPP_
    #define SOUND_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class Sound {
    public:
        Sound(std::string filepath);

        sf::SoundBuffer soundBuffer;
        sf::Sound sound;
    private:
};

#endif /* !SOUND_HPP_ */
