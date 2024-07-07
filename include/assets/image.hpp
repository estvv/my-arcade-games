#ifndef IMAGE_HPP_
    #define IMAGE_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <memory>

using namespace std;

class Image {
    public:
        Image(const string &filepath, sf::Vector2f pos, sf::Vector2f scale);
        void display(sf::RenderWindow &window);

        sf::Sprite sprite;
        shared_ptr<sf::Texture> texture;
    private:
};

#endif /* !IMAGE_HPP_ */
