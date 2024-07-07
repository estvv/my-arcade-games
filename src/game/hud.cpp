#include "hud.hpp"
#include "all.hpp"

Hud::Hud(All *all)
{
    initText(*all);
}

void Hud::initText(All &all)
{
    scoreText.setString("SCORE : 0");
    scoreText.setFont(all.assets.fonts.at(0).font);
    scoreText.setCharacterSize(30);
    scoreText.setPosition(sf::Vector2f(0, 0));
    roundText.setString("ROUND : 0");
    roundText.setFont(all.assets.fonts.at(0).font);
    roundText.setCharacterSize(30);
    roundText.setPosition(sf::Vector2f(600, 0));
}

void Hud::textDisplay(sf::RenderWindow &window)
{
    window.draw(scoreText);
    window.draw(roundText);
}
