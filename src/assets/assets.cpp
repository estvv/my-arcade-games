#include "assets.hpp"
#include "all.hpp"
#include <string>

Assets::Assets(void)
{
    images.push_back(Image("./data/image/my_arcade_games_logo.png", sf::Vector2f(20, -250), sf::Vector2f(6, 6)));
    images.push_back(Image("./data/image/my_snake_logo.png", sf::Vector2f(20, -200), sf::Vector2f(6, 6)));
    images.push_back(Image("./data/image/my_breakout_logo.png", sf::Vector2f(20, -200), sf::Vector2f(6, 6)));
    images.push_back(Image("./data/image/my_bubble_shooter_logo.png", sf::Vector2f(20, -200), sf::Vector2f(6, 6)));
    images.push_back(Image("./data/image/my_tetris_logo.png", sf::Vector2f(20, -200), sf::Vector2f(6, 6)));
    fonts.push_back(Font("./data/font/pixel.ttf"));
    sounds.push_back(Sound("./data/sounds/sound_click_button.ogg"));
    sounds.push_back(Sound("./data/sounds/sound_hover_button.ogg"));
    sounds.push_back(Sound("./data/sounds/sound_input_button.ogg"));
    sounds.push_back(Sound("./data/sounds/sound_input_escape.ogg"));
    sounds.push_back(Sound("./data/sounds/sound_dying_snake.ogg"));
    sounds.push_back(Sound("./data/sounds/sound_eating_apple.ogg"));
}

void Assets::displayImages(All &all)
{
    if (all.screen_id == mainMenu)
        images.at(0).display(all.window);
    if (all.screen_id == choosingSnakeGameMenu)
        images.at(1).display(all.window);
    if (all.screen_id == choosingBreakoutGameMenu)
        images.at(2).display(all.window);
    if (all.screen_id == choosingBubbleShooterGameMenu)
        images.at(3).display(all.window);
    if (all.screen_id == choosingTetrisGameMenu)
        images.at(4).display(all.window);
}
