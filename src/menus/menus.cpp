#include "menus.hpp"
#include "all.hpp"
#include <iostream>

Menus::Menus(All *all, sf::RenderWindow &window)
{
    for (int i = 0; i <= screenCounter; i++)
        menusList.push_back(Menu(window));
    initMain(*all);
    initSettings(*all);
    initLeaderboard(*all);
    initDead(*all);
    initPause(*all);
    initHelp(*all);
    initChoosingGame(*all);
}

void Menus::initMain(All &all)
{
    menusList.at(mainMenu).actionButtonsList.push_back(actionButtons(all, "PLAY", sf::Vector2f(400, 50), sf::Vector2f(200, 300), goToChoosingSnakeGameMenu));
    menusList.at(mainMenu).actionButtonsList.push_back(actionButtons(all, "TETRIS", sf::Vector2f(100, 50), sf::Vector2f(600, 200), goToTetrisGameScreen));
    menusList.at(mainMenu).actionButtonsList.push_back(actionButtons(all, "SETTINGS", sf::Vector2f(400, 50), sf::Vector2f(200, 400), goToFirstSettingsMenu));
    menusList.at(mainMenu).actionButtonsList.push_back(actionButtons(all, "LEADERBOARD", sf::Vector2f(400, 50), sf::Vector2f(200, 500), goToLeaderboardMenu));
    menusList.at(mainMenu).actionButtonsList.push_back(actionButtons(all, "HELP", sf::Vector2f(400, 50), sf::Vector2f(200, 600), goToHelpMenu));
    menusList.at(mainMenu).actionButtonsList.push_back(actionButtons(all, "EXIT", sf::Vector2f(400, 50), sf::Vector2f(200, 700), goToExit));
    menusList.at(mainMenu).actionButtonsList.at(4).button_text.setFillColor(sf::Color(200, 0, 0));
}

void Menus::initSettings(All &all)
{
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "MASTER VOLUME", sf::Vector2f(400, 50), sf::Vector2f(200, 10)));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "-", sf::Vector2f(100, 50), sf::Vector2f(200, 80), masterVolumeDown));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "50", sf::Vector2f(100, 50), sf::Vector2f(350, 80)));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "+", sf::Vector2f(100, 50), sf::Vector2f(500, 80), masterVolumeUp));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "MUSIC", sf::Vector2f(400, 50), sf::Vector2f(200, 200)));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "-", sf::Vector2f(100, 50), sf::Vector2f(200, 270), musicVolumeDown));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "50", sf::Vector2f(100, 50), sf::Vector2f(350, 270)));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "+", sf::Vector2f(100, 50), sf::Vector2f(500, 270), musicVolumeUp));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "SOUNDS", sf::Vector2f(400, 50), sf::Vector2f(200, 390)));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "-", sf::Vector2f(100, 50), sf::Vector2f(200, 460), soundVolumeDown));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "50", sf::Vector2f(100, 50), sf::Vector2f(350, 460)));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "+", sf::Vector2f(100, 50), sf::Vector2f(500, 460), soundVolumeUp));
    menusList.at(settingsFirstMenu).buttonsList.push_back(Buttons(all, "THEMES", sf::Vector2f(400, 50), sf::Vector2f(200, 580)));
    menusList.at(settingsFirstMenu).toggledButtonsList.push_back(toggledButtons(all, "", sf::Vector2f(100, 50), sf::Vector2f(200, 650), resetTheme, noneToggled, sf::Color::Black));
    menusList.at(settingsFirstMenu).toggledButtonsList.at(0).button_rect.setOutlineColor(sf::Color::White);
    menusList.at(settingsFirstMenu).toggledButtonsList.push_back(toggledButtons(all, "", sf::Vector2f(100, 50), sf::Vector2f(350, 650), setLightBlueTheme, noneToggled, sf::Color(204, 219, 253)));
    menusList.at(settingsFirstMenu).toggledButtonsList.push_back(toggledButtons(all, "", sf::Vector2f(100, 50), sf::Vector2f(500, 650), setRedAndYellowTheme, noneToggled, sf::Color(255, 102, 102)));
    menusList.at(settingsFirstMenu).toggledButtonsList.push_back(toggledButtons(all, "", sf::Vector2f(100, 50), sf::Vector2f(275, 720), setPinkTheme, noneToggled, sf::Color(255, 204, 230)));
    menusList.at(settingsFirstMenu).toggledButtonsList.push_back(toggledButtons(all, "", sf::Vector2f(100, 50), sf::Vector2f(425, 720), noneToggled, noneToggled, sf::Color(255, 255, 255)));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "NEXT", sf::Vector2f(100, 50), sf::Vector2f(690, 740), goToSecondSettingsMenu));
    menusList.at(settingsFirstMenu).actionButtonsList.push_back(actionButtons(all, "BACK", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToMainMenu));
    menusList.at(settingsSecondMenu).actionButtonsList.push_back(actionButtons(all, "BACK", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToFirstSettingsMenu));
    menusList.at(settingsSecondMenu).toggledButtonsList.push_back(toggledButtons(all, "Z", sf::Vector2f(170, 50), sf::Vector2f(50, 50), noneToggled, upInputKey, all.colors.menusColors.mainColor));
    menusList.at(settingsSecondMenu).buttonsList.push_back(Buttons(all, "MOVE UP", sf::Vector2f(280, 50), sf::Vector2f(300, 50)));
    menusList.at(settingsSecondMenu).toggledButtonsList.push_back(toggledButtons(all, "Q", sf::Vector2f(170, 50), sf::Vector2f(50, 110), noneToggled, leftInputKey, all.colors.menusColors.mainColor));
    menusList.at(settingsSecondMenu).buttonsList.push_back(Buttons(all, "MOVE LEFT", sf::Vector2f(280, 50), sf::Vector2f(300, 110)));
    menusList.at(settingsSecondMenu).toggledButtonsList.push_back(toggledButtons(all, "S", sf::Vector2f(170, 50), sf::Vector2f(50, 170), noneToggled, downInputKey, all.colors.menusColors.mainColor));
    menusList.at(settingsSecondMenu).buttonsList.push_back(Buttons(all, "MOVE DOWN", sf::Vector2f(280, 50), sf::Vector2f(300, 170)));
    menusList.at(settingsSecondMenu).toggledButtonsList.push_back(toggledButtons(all, "D", sf::Vector2f(170, 50), sf::Vector2f(50, 230), noneToggled, rightInputKey, all.colors.menusColors.mainColor));
    menusList.at(settingsSecondMenu).buttonsList.push_back(Buttons(all, "MOVE RIGHT", sf::Vector2f(280, 50), sf::Vector2f(300, 230)));
    menusList.at(settingsSecondMenu).toggledButtonsList.push_back(toggledButtons(all, "SPACE", sf::Vector2f(170, 50), sf::Vector2f(50, 290), noneToggled, noneToggled, all.colors.menusColors.mainColor));
}

void Menus::initLeaderboard(All &all)
{
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "1ST", sf::Vector2f(100, 50), sf::Vector2f(100, 60)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 60)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 60)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "2ND", sf::Vector2f(100, 50), sf::Vector2f(100, 130)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 130)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 130)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "3RD", sf::Vector2f(100, 50), sf::Vector2f(100, 200)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 200)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 200)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "4TH", sf::Vector2f(100, 50), sf::Vector2f(100, 270)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 270)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 270)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "5TH", sf::Vector2f(100, 50), sf::Vector2f(100, 340)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 340)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 340)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "6TH", sf::Vector2f(100, 50), sf::Vector2f(100, 410)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 410)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 410)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "7TH", sf::Vector2f(100, 50), sf::Vector2f(100, 480)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 480)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 480)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "8TH", sf::Vector2f(100, 50), sf::Vector2f(100, 550)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 550)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 550)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "9TH", sf::Vector2f(100, 50), sf::Vector2f(100, 620)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "NAME", sf::Vector2f(300, 50), sf::Vector2f(250, 620)));
    menusList.at(leaderboardMenu).buttonsList.push_back(Buttons(all, "VAL", sf::Vector2f(150, 50), sf::Vector2f(600, 620)));
    menusList.at(leaderboardMenu).actionButtonsList.push_back(actionButtons(all, "BACK", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToMainMenu));
}

void Menus::initDead(All &all)
{
    menusList.at(deadMenu).actionButtonsList.push_back(actionButtons(all, "RETRY", sf::Vector2f(400, 50), sf::Vector2f(200, 300), noneAction));
    menusList.at(deadMenu).actionButtonsList.push_back(actionButtons(all, "MENU", sf::Vector2f(400, 50), sf::Vector2f(200, 400), goToMainMenu));
    menusList.at(deadMenu).buttonsList.push_back(Buttons(all, "SCORE :", sf::Vector2f(200, 50), sf::Vector2f(200, 500)));
    menusList.at(deadMenu).buttonsList.push_back(Buttons(all, "0", sf::Vector2f(150, 50), sf::Vector2f(450, 500)));
    menusList.at(deadMenu).buttonsList.push_back(Buttons(all, "HIGHEST :", sf::Vector2f(200, 50), sf::Vector2f(200, 600)));
    menusList.at(deadMenu).buttonsList.push_back(Buttons(all, "X", sf::Vector2f(150, 50), sf::Vector2f(450, 600)));
}

void Menus::initPause(All &all)
{
    menusList.at(pauseMenu).actionButtonsList.push_back(actionButtons(all, "CONTINUE", sf::Vector2f(400, 50), sf::Vector2f(200, 300), noneAction));
    menusList.at(pauseMenu).actionButtonsList.push_back(actionButtons(all, "MENU", sf::Vector2f(400, 50), sf::Vector2f(200, 400), goToMainMenu));
    menusList.at(pauseMenu).buttonsList.push_back(Buttons(all, "SCORE :", sf::Vector2f(200, 50), sf::Vector2f(200, 500)));
    menusList.at(pauseMenu).buttonsList.push_back(Buttons(all, "0", sf::Vector2f(150, 50), sf::Vector2f(450, 500)));
    menusList.at(pauseMenu).buttonsList.push_back(Buttons(all, "HIGHEST :", sf::Vector2f(200, 50), sf::Vector2f(200, 600)));
    menusList.at(pauseMenu).buttonsList.push_back(Buttons(all, "X", sf::Vector2f(150, 50), sf::Vector2f(450, 600)));
}

void Menus::initHelp(All &all)
{
    menusList.at(helpMenu).buttonsList.push_back(Buttons(all, "CONTROLS", sf::Vector2f(400, 50), sf::Vector2f(200, 130)));
    menusList.at(helpMenu).buttonsList.push_back(Buttons(all, "Z", sf::Vector2f(50, 50), sf::Vector2f(260, 190)));
    menusList.at(helpMenu).buttonsList.push_back(Buttons(all, "Q", sf::Vector2f(50, 50), sf::Vector2f(200, 250)));
    menusList.at(helpMenu).buttonsList.push_back(Buttons(all, "S", sf::Vector2f(50, 50), sf::Vector2f(260, 250)));
    menusList.at(helpMenu).buttonsList.push_back(Buttons(all, "D", sf::Vector2f(50, 50), sf::Vector2f(320, 250)));
    menusList.at(helpMenu).buttonsList.push_back(Buttons(all, "SPACE", sf::Vector2f(170, 50), sf::Vector2f(200, 310)));
    menusList.at(helpMenu).buttonsList.push_back(Buttons(all, "^", sf::Vector2f(50, 50), sf::Vector2f(485, 190)));
    menusList.at(helpMenu).buttonsList.push_back(Buttons(all, "<", sf::Vector2f(50, 50), sf::Vector2f(425, 250)));
    menusList.at(helpMenu).buttonsList.push_back(Buttons(all, "-", sf::Vector2f(50, 50), sf::Vector2f(485, 250)));
    menusList.at(helpMenu).buttonsList.push_back(Buttons(all, ">", sf::Vector2f(50, 50), sf::Vector2f(545, 250)));
    menusList.at(helpMenu).buttonsList.push_back(Buttons(all, "SPACE", sf::Vector2f(170, 50), sf::Vector2f(425, 310)));
    menusList.at(helpMenu).buttonsList.push_back(Buttons(all, "OBJECTIVE", sf::Vector2f(400, 50), sf::Vector2f(200, 400)));
    menusList.at(helpMenu).buttonsList.push_back(Buttons(all, "EAT APPLES", sf::Vector2f(250, 50), sf::Vector2f(270, 460)));
    menusList.at(helpMenu).buttonsList.push_back(Buttons(all, "AVOID WALLS", sf::Vector2f(250, 50), sf::Vector2f(270, 520)));
    menusList.at(helpMenu).actionButtonsList.push_back(actionButtons(all, "BACK", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToMainMenu));
}

void Menus::initChoosingGame(All &all)
{
    menusList.at(choosingSnakeGameMenu).actionButtonsList.push_back(actionButtons(all, "PLAY", sf::Vector2f(250, 50), sf::Vector2f(275, 375), goToSnakeGameScreen));
    menusList.at(choosingSnakeGameMenu).actionButtonsList.push_back(actionButtons(all, "BACK", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToMainMenu));
    menusList.at(choosingSnakeGameMenu).actionButtonsList.push_back(actionButtons(all, "NEXT", sf::Vector2f(100, 50), sf::Vector2f(690, 740), goToChoosingBreakoutGameMenu));
    menusList.at(choosingBreakoutGameMenu).actionButtonsList.push_back(actionButtons(all, "PLAY", sf::Vector2f(250, 50), sf::Vector2f(275, 375), goToBreakoutGameScreen));
    menusList.at(choosingBreakoutGameMenu).actionButtonsList.push_back(actionButtons(all, "BACK", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToChoosingSnakeGameMenu));
    menusList.at(choosingBreakoutGameMenu).actionButtonsList.push_back(actionButtons(all, "NEXT", sf::Vector2f(100, 50), sf::Vector2f(690, 740), goToChoosingBubbleShooterGameMenu));
    menusList.at(choosingBubbleShooterGameMenu).actionButtonsList.push_back(actionButtons(all, "PLAY", sf::Vector2f(250, 50), sf::Vector2f(275, 375), goToBubbleShooterGameScreen));
    menusList.at(choosingBubbleShooterGameMenu).actionButtonsList.push_back(actionButtons(all, "BACK", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToChoosingBreakoutGameMenu));
    menusList.at(choosingBubbleShooterGameMenu).actionButtonsList.push_back(actionButtons(all, "NEXT", sf::Vector2f(100, 50), sf::Vector2f(690, 740), goToChoosingTetrisGameMenu));
    menusList.at(choosingTetrisGameMenu).actionButtonsList.push_back(actionButtons(all, "PLAY", sf::Vector2f(250, 50), sf::Vector2f(275, 375), goToTetrisGameScreen));
    menusList.at(choosingTetrisGameMenu).actionButtonsList.push_back(actionButtons(all, "BACK", sf::Vector2f(100, 50), sf::Vector2f(10, 740), goToChoosingBubbleShooterGameMenu));
}

void Menus::updateMenusColors(MenusColors menusColors)
{
    for (Menu &menu : menusList) {
        for (actionButtons &button : menu.actionButtonsList) {
            button.button_rect.setOutlineColor(menusColors.button);
            button.button_text.setFillColor(menusColors.buttonText);
        }
        for (toggledButtons &button : menu.toggledButtonsList) {
            button.button_rect.setOutlineColor(menusColors.button);
            button.button_text.setFillColor(menusColors.buttonText);
        }
        for (Buttons &button : menu.buttonsList) {
            button.button_rect.setOutlineColor(menusColors.button);
            button.button_text.setFillColor(menusColors.buttonText);
        }
    }
}
