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
    menusList.at(mainMenu).actionButtonsList.push_back(actionButtons(all, "PLAY", sf::Vector2f(400, 50), sf::Vector2f(200, 300), playButtonFunction));
    menusList.at(mainMenu).actionButtonsList.push_back(actionButtons(all, "SETTINGS", sf::Vector2f(400, 50), sf::Vector2f(200, 400), goToFirstSettingsMenu));
    menusList.at(mainMenu).actionButtonsList.push_back(actionButtons(all, "LEADERBOARD", sf::Vector2f(400, 50), sf::Vector2f(200, 500), leaderButtonFunction));
    menusList.at(mainMenu).actionButtonsList.push_back(actionButtons(all, "HELP", sf::Vector2f(400, 50), sf::Vector2f(200, 600), helpButtonFunction));
    menusList.at(mainMenu).actionButtonsList.push_back(actionButtons(all, "EXIT", sf::Vector2f(400, 50), sf::Vector2f(200, 700), exitButtonFunction));
}

void Menus::initSettings(All &all)
{
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "MASTER VOLUME", sf::Vector2f(400, 50), sf::Vector2f(200, 10), noneAction));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "-", sf::Vector2f(100, 50), sf::Vector2f(200, 80), masterVolumeDown));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "50", sf::Vector2f(100, 50), sf::Vector2f(350, 80), noneAction));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "+", sf::Vector2f(100, 50), sf::Vector2f(500, 80), masterVolumeUp));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "MUSIC", sf::Vector2f(400, 50), sf::Vector2f(200, 200), noneAction));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "-", sf::Vector2f(100, 50), sf::Vector2f(200, 270), musicVolumeDown));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "50", sf::Vector2f(100, 50), sf::Vector2f(350, 270), noneAction));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "+", sf::Vector2f(100, 50), sf::Vector2f(500, 270), musicVolumeUp));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "SOUNDS", sf::Vector2f(400, 50), sf::Vector2f(200, 390), noneAction));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "-", sf::Vector2f(100, 50), sf::Vector2f(200, 460), soundVolumeDown));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "50", sf::Vector2f(100, 50), sf::Vector2f(350, 460), noneAction));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "+", sf::Vector2f(100, 50), sf::Vector2f(500, 460), soundVolumeUp));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "THEMES", sf::Vector2f(400, 50), sf::Vector2f(200, 580), noneAction));
    menusList.at(settingsFirstMenu).toggledButtonsList.push_back(toggledButtons(all, "", sf::Vector2f(100, 50), sf::Vector2f(200, 650), resetTheme, noneToggled, sf::Color::Black));
    menusList.at(settingsFirstMenu).toggledButtonsList.at(0).button_rect.setOutlineColor(sf::Color::White);
    menusList.at(settingsFirstMenu).toggledButtonsList.push_back(toggledButtons(all, "", sf::Vector2f(100, 50), sf::Vector2f(350, 650), setLightBlueTheme, noneToggled, sf::Color(204, 219, 253)));
    menusList.at(settingsFirstMenu).toggledButtonsList.push_back(toggledButtons(all, "", sf::Vector2f(100, 50), sf::Vector2f(500, 650), setRedAndYellowTheme, noneToggled, sf::Color(255, 102, 102)));
    menusList.at(settingsFirstMenu).toggledButtonsList.push_back(toggledButtons(all, "", sf::Vector2f(100, 50), sf::Vector2f(275, 720), setPinkTheme, noneToggled, sf::Color(255, 204, 230)));
    menusList.at(settingsFirstMenu).toggledButtonsList.push_back(toggledButtons(all, "", sf::Vector2f(100, 50), sf::Vector2f(425, 720), noneToggled, noneToggled, sf::Color(255, 255, 255)));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "NEXT", sf::Vector2f(100, 50), sf::Vector2f(690, 740), goToSecondSettingsMenu));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "PREV", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToMainMenu));
    menusList.at(settingsSecondMenu).actionButtonsList.push_back(actionButtons(all, "PREV", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToFirstSettingsMenu));
    menusList.at(settingsSecondMenu).toggledButtonsList.push_back(toggledButtons(all, "Z", sf::Vector2f(170, 50), sf::Vector2f(50, 50), noneToggled, upInputKey, all.colors.mainColor));
    menusList.at(settingsSecondMenu).toggledButtonsList.push_back(toggledButtons(all, "Q", sf::Vector2f(170, 50), sf::Vector2f(50, 110), noneToggled, leftInputKey, all.colors.mainColor));
    menusList.at(settingsSecondMenu).toggledButtonsList.push_back(toggledButtons(all, "S", sf::Vector2f(170, 50), sf::Vector2f(50, 170), noneToggled, downInputKey, all.colors.mainColor));
    menusList.at(settingsSecondMenu).toggledButtonsList.push_back(toggledButtons(all, "D", sf::Vector2f(170, 50), sf::Vector2f(50, 230), noneToggled, rightInputKey, all.colors.mainColor));
    menusList.at(settingsSecondMenu).toggledButtonsList.push_back(toggledButtons(all, "SPACE", sf::Vector2f(170, 50), sf::Vector2f(50, 290), noneToggled, noneToggled, all.colors.mainColor));
}

void Menus::initLeaderboard(All &all)
{
    return;
/*     menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "1ST", sf::Vector2f(100, 50), sf::Vector2f(100, 60), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 60), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 60), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "2ND", sf::Vector2f(100, 50), sf::Vector2f(100, 130), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 130), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 130), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "3RD", sf::Vector2f(100, 50), sf::Vector2f(100, 200), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 200), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 200), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "4TH", sf::Vector2f(100, 50), sf::Vector2f(100, 270), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 270), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 270), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "5TH", sf::Vector2f(100, 50), sf::Vector2f(100, 340), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 340), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 340), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "6TH", sf::Vector2f(100, 50), sf::Vector2f(100, 410), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 410), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 410), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "7TH", sf::Vector2f(100, 50), sf::Vector2f(100, 480), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 480), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 480), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "8TH", sf::Vector2f(100, 50), sf::Vector2f(100, 550), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 550), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 550), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "9TH", sf::Vector2f(100, 50), sf::Vector2f(100, 620), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 620), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 620), none, 0));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(Buttons(all, "PREV", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToMainMenu, 0)); */
}
