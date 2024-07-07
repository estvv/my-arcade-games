#ifndef FONT_HPP_
    #define FONT_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

using namespace std;

class Font {
    public:
        Font(string filepath);

        sf::Font font;
    private:
};

#endif /* !FONT_HPP_ */
