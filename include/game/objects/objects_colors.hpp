#ifndef OBJECTS_COLORS_HPP_
    #define OBJECTS_COLORS_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include "vector"

using namespace std;

class ObjectsColors {
    public:
        ObjectsColors(void);
        sf::Color getRandomObjectColor(vector<sf::Color> objects);

        vector<sf::Color> ballColors;
        vector<sf::Color> bricksColors;
    private:
};

#endif /* !OBJECTS_COLORS_HPP_ */
