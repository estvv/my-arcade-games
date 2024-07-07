#ifndef SOUND_HPP_
    #define SOUND_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <memory>

using namespace std;

class Sound {
    public:
        Sound(string filepath);

        sf::Sound sound;
        shared_ptr<sf::SoundBuffer> soundBuffer;
    private:
};

#endif /* !SOUND_HPP_ */
