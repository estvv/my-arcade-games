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
    menusList.push_back(Menu(window));
    menusList.push_back(Menu(window));
    initMain(*all);
    initSettings(*all);
    initLeaderboard(*all);
    initDead(*all);
    initPause(*all);
    initHelp(*all);
}

void Menus::initMain(All &all)
{
    menusList.at(mainMenu).actionButtonsList.push_back(actionButtons(all, "PLAY", sf::Vector2f(400, 50), sf::Vector2f(200, 300), playButtonFunction));
    menusList.at(mainMenu).actionButtonsList.push_back(actionButtons(all, "SETTINGS", sf::Vector2f(400, 50), sf::Vector2f(200, 400), goToFirstSettingsMenu));
    menusList.at(mainMenu).actionButtonsList.push_back(actionButtons(all, "LEADERBOARD", sf::Vector2f(400, 50), sf::Vector2f(200, 500), leaderButtonFunction));
    menusList.at(mainMenu).actionButtonsList.push_back(actionButtons(all, "HELP", sf::Vector2f(400, 50), sf::Vector2f(200, 600), helpButtonFunction));
    menusList.at(mainMenu).actionButtonsList.push_back(actionButtons(all, "EXIT", sf::Vector2f(400, 50), sf::Vector2f(200, 700), exitButtonFunction));
    menusList.at(mainMenu).actionButtonsList.at(4).button_text.setFillColor(sf::Color(200, 0, 0));
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
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "BACK", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToMainMenu));
    menusList.at(settingsSecondMenu).actionButtonsList.push_back(actionButtons(all, "BACK", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToFirstSettingsMenu));
    menusList.at(settingsSecondMenu).toggledButtonsList.push_back(toggledButtons(all, "Z", sf::Vector2f(170, 50), sf::Vector2f(50, 50), noneToggled, upInputKey, all.colors.mainColor));
    menusList.at(settingsSecondMenu).actionButtonsList.push_back(actionButtons(all, "MOVE UP", sf::Vector2f(280, 50), sf::Vector2f(300, 50), noneAction));
    menusList.at(settingsSecondMenu).toggledButtonsList.push_back(toggledButtons(all, "Q", sf::Vector2f(170, 50), sf::Vector2f(50, 110), noneToggled, leftInputKey, all.colors.mainColor));
    menusList.at(settingsSecondMenu).actionButtonsList.push_back(actionButtons(all, "MOVE LEFT", sf::Vector2f(280, 50), sf::Vector2f(300, 110), noneAction));
    menusList.at(settingsSecondMenu).toggledButtonsList.push_back(toggledButtons(all, "S", sf::Vector2f(170, 50), sf::Vector2f(50, 170), noneToggled, downInputKey, all.colors.mainColor));
    menusList.at(settingsSecondMenu).actionButtonsList.push_back(actionButtons(all, "MOVE DOWN", sf::Vector2f(280, 50), sf::Vector2f(300, 170), noneAction));
    menusList.at(settingsSecondMenu).toggledButtonsList.push_back(toggledButtons(all, "D", sf::Vector2f(170, 50), sf::Vector2f(50, 230), noneToggled, rightInputKey, all.colors.mainColor));
    menusList.at(settingsSecondMenu).actionButtonsList.push_back(actionButtons(all, "MOVE RIGHT", sf::Vector2f(280, 50), sf::Vector2f(300, 230), noneAction));
    menusList.at(settingsSecondMenu).toggledButtonsList.push_back(toggledButtons(all, "SPACE", sf::Vector2f(170, 50), sf::Vector2f(50, 290), noneToggled, noneToggled, all.colors.mainColor));
}

void Menus::initLeaderboard(All &all)
{
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "1ST", sf::Vector2f(100, 50), sf::Vector2f(100, 60), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 60), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 60), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "2ND", sf::Vector2f(100, 50), sf::Vector2f(100, 130), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 130), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 130), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "3RD", sf::Vector2f(100, 50), sf::Vector2f(100, 200), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 200), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 200), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "4TH", sf::Vector2f(100, 50), sf::Vector2f(100, 270), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 270), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 270), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "5TH", sf::Vector2f(100, 50), sf::Vector2f(100, 340), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 340), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 340), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "6TH", sf::Vector2f(100, 50), sf::Vector2f(100, 410), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 410), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 410), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "7TH", sf::Vector2f(100, 50), sf::Vector2f(100, 480), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 480), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 480), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "8TH", sf::Vector2f(100, 50), sf::Vector2f(100, 550), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 550), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 550), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "9TH", sf::Vector2f(100, 50), sf::Vector2f(100, 620), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 620), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 620), noneAction));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "BACK", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToMainMenu));
}

void Menus::initDead(All &all)
{
    menusList.at(deadMenu).actionButtonsList.push_back(actionButtons(all, "RETRY", sf::Vector2f(400, 50), sf::Vector2f(200, 300), playButtonFunction));
    menusList.at(deadMenu).actionButtonsList.push_back(actionButtons(all, "MENU", sf::Vector2f(400, 50), sf::Vector2f(200, 400), goToMainMenu));
    menusList.at(deadMenu).actionButtonsList.push_back(actionButtons(all, "SCORE :", sf::Vector2f(200, 50), sf::Vector2f(200, 500), noneAction));
    menusList.at(deadMenu).actionButtonsList.push_back(actionButtons(all, "0", sf::Vector2f(150, 50), sf::Vector2f(450, 500), noneAction));
    menusList.at(deadMenu).actionButtonsList.push_back(actionButtons(all, "HIGHEST :", sf::Vector2f(200, 50), sf::Vector2f(200, 600), noneAction));
    menusList.at(deadMenu).actionButtonsList.push_back(actionButtons(all, "X", sf::Vector2f(150, 50), sf::Vector2f(450, 600), noneAction));
}

void Menus::initPause(All &all)
{
    menusList.at(pauseMenu).actionButtonsList.push_back(actionButtons(all, "CONTINUE", sf::Vector2f(400, 50), sf::Vector2f(200, 300), playButtonFunction));
    menusList.at(pauseMenu).actionButtonsList.push_back(actionButtons(all, "MENU", sf::Vector2f(400, 50), sf::Vector2f(200, 400), goToMainMenu));
    menusList.at(pauseMenu).actionButtonsList.push_back(actionButtons(all, "SCORE :", sf::Vector2f(200, 50), sf::Vector2f(200, 500), noneAction));
    menusList.at(pauseMenu).actionButtonsList.push_back(actionButtons(all, "0", sf::Vector2f(150, 50), sf::Vector2f(450, 500), noneAction));
    menusList.at(pauseMenu).actionButtonsList.push_back(actionButtons(all, "HIGHEST :", sf::Vector2f(200, 50), sf::Vector2f(200, 600), noneAction));
    menusList.at(pauseMenu).actionButtonsList.push_back(actionButtons(all, "X", sf::Vector2f(150, 50), sf::Vector2f(450, 600), noneAction));
}

void Menus::initHelp(All &all)
{
    menusList.at(helpMenu).actionButtonsList.push_back(actionButtons(all, "CONTROLS", sf::Vector2f(400, 50), sf::Vector2f(200, 130), noneAction));
    menusList.at(helpMenu).actionButtonsList.push_back(actionButtons(all, "Z", sf::Vector2f(50, 50), sf::Vector2f(260, 190), noneAction));
    menusList.at(helpMenu).actionButtonsList.push_back(actionButtons(all, "Q", sf::Vector2f(50, 50), sf::Vector2f(200, 250), noneAction));
    menusList.at(helpMenu).actionButtonsList.push_back(actionButtons(all, "S", sf::Vector2f(50, 50), sf::Vector2f(260, 250), noneAction));
    menusList.at(helpMenu).actionButtonsList.push_back(actionButtons(all, "D", sf::Vector2f(50, 50), sf::Vector2f(320, 250), noneAction));
    menusList.at(helpMenu).actionButtonsList.push_back(actionButtons(all, "SPACE", sf::Vector2f(170, 50), sf::Vector2f(200, 310), noneAction));
    menusList.at(helpMenu).actionButtonsList.push_back(actionButtons(all, "^", sf::Vector2f(50, 50), sf::Vector2f(485, 190), noneAction));
    menusList.at(helpMenu).actionButtonsList.push_back(actionButtons(all, "<", sf::Vector2f(50, 50), sf::Vector2f(425, 250), noneAction));
    menusList.at(helpMenu).actionButtonsList.push_back(actionButtons(all, "-", sf::Vector2f(50, 50), sf::Vector2f(485, 250), noneAction));
    menusList.at(helpMenu).actionButtonsList.push_back(actionButtons(all, ">", sf::Vector2f(50, 50), sf::Vector2f(545, 250), noneAction));
    menusList.at(helpMenu).actionButtonsList.push_back(actionButtons(all, "SPACE", sf::Vector2f(170, 50), sf::Vector2f(425, 310), noneAction));
    menusList.at(helpMenu).actionButtonsList.push_back(actionButtons(all, "OBJECTIVE", sf::Vector2f(400, 50), sf::Vector2f(200, 400), noneAction));
    menusList.at(helpMenu).actionButtonsList.push_back(actionButtons(all, "EAT APPLES", sf::Vector2f(250, 50), sf::Vector2f(270, 460), noneAction));
    menusList.at(helpMenu).actionButtonsList.push_back(actionButtons(all, "AVOID WALLS", sf::Vector2f(250, 50), sf::Vector2f(270, 520), noneAction));
    menusList.at(helpMenu).actionButtonsList.push_back(actionButtons(all, "BACK", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToMainMenu));
}
