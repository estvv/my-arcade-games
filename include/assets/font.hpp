#ifndef FONT_HPP_
    #define FONT_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class Font {
    public:
        Font(std::string filepath);

        sf::Font font;
    private:
};

#endif /* !FONT_HPP_ */
