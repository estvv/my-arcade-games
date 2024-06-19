#include "assets.hpp"
#include "all.hpp"
#include <string>

Assets::Assets(void)
{
    images.push_back(Image("./assets/image/my_snake_logo.png", sf::Vector2f(210, -50), sf::Vector2f(6, 6)));
    fonts.push_back(Font("./assets/font/pixel.ttf"));
/*     musics.push_back(Music("./assets/sounds/apple_eaten.ogg"));
    sounds.push_back(Sound("./assets/sounds/apple_eaten.ogg")); */
}

void Assets::displayImages(All &all)
{
/*     if (all.screen_id == mainMenu)
        images.at(0).display(all.window); */
}
