#ifndef MUSIC_HPP_
    #define MUSIC_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <memory>

using namespace std;

class Music {
    public:
        Music(const string &filepath);

        shared_ptr<sf::Music> music;
    private:
};

#endif /* !MUSIC_HPP_ */
