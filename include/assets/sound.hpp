#ifndef SOUND_HPP_
    #define SOUND_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <memory>

class Sound {
    public:
        Sound(std::string filepath);

        sf::Sound sound;
        std::shared_ptr<sf::SoundBuffer> soundBuffer;
    private:
};

#endif /* !SOUND_HPP_ */
