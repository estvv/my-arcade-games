#include "menus.hpp"
#include "all.hpp"
#include <iostream>

Menus::Menus(All *all, sf::RenderWindow &window)
{
    menusList.push_back(Menu(window));
    menusList.push_back(Menu(window));
    menusList.push_back(Menu(window));
    menusList.push_back(Menu(window));
    menusList.push_back(Menu(window));
    initMain(*all);
    initSettings(*all);
    initLeaderboard(*all);
}

void Menus::initMain(All &all)
{
    menusList.at(mainMenu).buttonsList.push_back(Buttons(all, "PLAY", sf::Vector2f(400, 50), sf::Vector2f(200, 300), playButtonFunction, 0));
    menusList.at(mainMenu).buttonsList.push_back(Buttons(all, "SETTINGS", sf::Vector2f(400, 50), sf::Vector2f(200, 400), goToFirstSettingsMenu, 0));
    menusList.at(mainMenu).buttonsList.push_back(Buttons(all, "LEADERBOARD", sf::Vector2f(400, 50), sf::Vector2f(200, 500), leaderButtonFunction, 0));
    menusList.at(mainMenu).buttonsList.push_back(Buttons(all, "HELP", sf::Vector2f(400, 50), sf::Vector2f(200, 600), helpButtonFunction, 0));
    menusList.at(mainMenu).buttonsList.push_back(Buttons(all, "EXIT", sf::Vector2f(400, 50), sf::Vector2f(200, 700), exitButtonFunction, 0));
}

void Menus::initSettings(All &all)
{
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "MASTER VOLUME", sf::Vector2f(400, 50), sf::Vector2f(200, 10), none, 0));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "-", sf::Vector2f(100, 50), sf::Vector2f(200, 80), masterVolumeDown, 1));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "50", sf::Vector2f(100, 50), sf::Vector2f(350, 80), none, 1));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "+", sf::Vector2f(100, 50), sf::Vector2f(500, 80), masterVolumeUp, 1));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "MUSIC", sf::Vector2f(400, 50), sf::Vector2f(200, 200), none, 1));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "-", sf::Vector2f(100, 50), sf::Vector2f(200, 270), musicVolumeDown, 1));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "50", sf::Vector2f(100, 50), sf::Vector2f(350, 270), none, 1));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "+", sf::Vector2f(100, 50), sf::Vector2f(500, 270), musicVolumeUp, 1));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "SOUNDS", sf::Vector2f(400, 50), sf::Vector2f(200, 390), none, 1));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "-", sf::Vector2f(100, 50), sf::Vector2f(200, 460), soundVolumeDown, 1));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "50", sf::Vector2f(100, 50), sf::Vector2f(350, 460), none, 1));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "+", sf::Vector2f(100, 50), sf::Vector2f(500, 460), soundVolumeUp, 1));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "THEMES", sf::Vector2f(400, 50), sf::Vector2f(200, 580), none, 0));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "", sf::Vector2f(100, 50), sf::Vector2f(200, 650), resetTheme, 0));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "", sf::Vector2f(100, 50), sf::Vector2f(350, 650), setLightBlueTheme, 0));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "", sf::Vector2f(100, 50), sf::Vector2f(500, 650), setRedAndYellowTheme, 0));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "", sf::Vector2f(100, 50), sf::Vector2f(275, 720), setPinkTheme, 0));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "", sf::Vector2f(100, 50), sf::Vector2f(425, 720), none, 0));
    menusList.at(settingsFirstMenu).buttonsList.at(13).button_rect.setFillColor(sf::Color::Black);
    menusList.at(settingsFirstMenu).buttonsList.at(14).button_rect.setFillColor(sf::Color(204, 219, 253));
    menusList.at(settingsFirstMenu).buttonsList.at(15).button_rect.setFillColor(sf::Color(255, 102, 102));
    menusList.at(settingsFirstMenu).buttonsList.at(16).button_rect.setFillColor(sf::Color(255, 204, 230));
    menusList.at(settingsFirstMenu).buttonsList.at(17).button_rect.setFillColor(sf::Color(255, 255, 255));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "NEXT", sf::Vector2f(100, 50), sf::Vector2f(690, 740), goToSecondSettingsMenu, 0));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "PREV", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToMainMenu, 0));
    menusList.at(settingsSecondMenu).buttonsList.push_back(Buttons(all, "PREV", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToFirstSettingsMenu, 0));
    menusList.at(settingsSecondMenu).buttonsList.push_back(Buttons(all, "Z", sf::Vector2f(50, 50), sf::Vector2f(50, 50), none, 0));
    menusList.at(settingsSecondMenu).buttonsList.push_back(Buttons(all, "Q", sf::Vector2f(50, 50), sf::Vector2f(50, 110), none, 0));
    menusList.at(settingsSecondMenu).buttonsList.push_back(Buttons(all, "S", sf::Vector2f(50, 50), sf::Vector2f(50, 170), none, 0));
    menusList.at(settingsSecondMenu).buttonsList.push_back(Buttons(all, "D", sf::Vector2f(50, 50), sf::Vector2f(50, 230), none, 0));
    menusList.at(settingsSecondMenu).buttonsList.push_back(Buttons(all, "SPACE", sf::Vector2f(170, 50), sf::Vector2f(50, 290), none, 0));
}

void Menus::initLeaderboard(All &all)
{
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "1ST", sf::Vector2f(100, 50), sf::Vector2f(100, 60), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 60), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 60), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "2ND", sf::Vector2f(100, 50), sf::Vector2f(100, 130), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 130), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 130), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "3RD", sf::Vector2f(100, 50), sf::Vector2f(100, 200), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 200), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 200), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "4TH", sf::Vector2f(100, 50), sf::Vector2f(100, 270), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 270), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 270), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "5TH", sf::Vector2f(100, 50), sf::Vector2f(100, 340), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 340), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 340), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "6TH", sf::Vector2f(100, 50), sf::Vector2f(100, 410), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 410), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 410), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "7TH", sf::Vector2f(100, 50), sf::Vector2f(100, 480), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 480), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 480), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "8TH", sf::Vector2f(100, 50), sf::Vector2f(100, 550), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 550), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 550), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "9TH", sf::Vector2f(100, 50), sf::Vector2f(100, 620), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 620), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 620), none, 0));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "PREV", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToMainMenu, 0));
}
