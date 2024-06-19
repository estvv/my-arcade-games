#ifndef MUSIC_HPP_
    #define MUSIC_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class Music {
    public:
        Music(const std::string &filepath);

        sf::Music music;
    private:
};

#endif /* !MUSIC_HPP_ */
