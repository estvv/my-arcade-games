#include "all.hpp"

void goToMainMenu(All &all)
{
    all.screen_id = mainMenu;
}

void goToSnakeGameScreen(All &all)
{
    if (all.screen_id != pauseMenu) {
        all.game.score = 0;
        all.game.scoreText.setString("SCORE : 0");
        all.game.round = 1;
        all.game.roundText.setString("ROUND : 0");
        all.game.snakeGame.initSnake();
        all.menus.menusList.at(pauseMenu).actionButtonsList.at(0).func = [](All &all) {goToSnakeGameScreen(all);};
        all.menus.menusList.at(deadMenu).actionButtonsList.at(0).func = [](All &all) {goToSnakeGameScreen(all);};
    }
    all.menus.menusList.at(pauseMenu).buttonsList.at(1).button_text.setString(std::to_string(all.game.score));
    all.screen_id = snakePlayScreen;
    all.game.gameState = snake;
}

void goToBreakoutGameScreen(All &all)
{
    if (all.screen_id != pauseMenu) {
        all.game.score = 0;
        all.game.scoreText.setString("SCORE : 0");
        all.game.round = 1;
        all.game.roundText.setString("ROUND : 0");
        all.menus.menusList.at(pauseMenu).actionButtonsList.at(0).func = [](All &all) {goToBreakoutGameScreen(all);};
        all.menus.menusList.at(deadMenu).actionButtonsList.at(0).func = [](All &all) {goToBreakoutGameScreen(all);};
    }
    all.menus.menusList.at(pauseMenu).buttonsList.at(1).button_text.setString(std::to_string(all.game.score));
    all.screen_id = breakoutPlayScreen;
    all.game.gameState = breakout;
}

void goToBubbleShooterGameScreen(All &all)
{
    if (all.screen_id != pauseMenu) {
        all.game.score = 0;
        all.game.scoreText.setString("SCORE : 0");
        all.game.round = 1;
        all.game.roundText.setString("ROUND : 0");
        all.menus.menusList.at(pauseMenu).actionButtonsList.at(0).func = [](All &all) {goToBubbleShooterGameScreen(all);};
        all.menus.menusList.at(deadMenu).actionButtonsList.at(0).func = [](All &all) {goToBubbleShooterGameScreen(all);};
    }
    all.menus.menusList.at(pauseMenu).buttonsList.at(1).button_text.setString(std::to_string(all.game.score));
    all.screen_id = bubbleShooterPlayScreen;
    all.game.gameState = bubbleShooter;
}

void goToChoosingBubbleShooterGameMenu(All &all)
{
    all.screen_id = choosingBubbleShooterGameMenu;
}

void goToChoosingSnakeGameMenu(All &all)
{
    all.screen_id = choosingSnakeGameMenu;
}

void goToChoosingBreakoutGameMenu(All &all)
{
    all.screen_id = choosingBreakoutGameMenu;
}

void goToFirstSettingsMenu(All &all)
{
    all.screen_id = settingsFirstMenu;
}

void goToSecondSettingsMenu(All &all)
{
    all.screen_id = settingsSecondMenu;
}

void goToLeaderboardMenu(All &all)
{
    all.screen_id = leaderboardMenu;
}

void goToHelpMenu(All &all)
{
    all.screen_id = helpMenu;
}

void goToExit(All &all)
{
    all.window.close();
}

void masterVolumeUp(All &all)
{
    if (all.settings.masterVolume != 100) {
        all.settings.masterVolume += 10;
        all.menus.menusList.at(settingsFirstMenu).buttonsList.at(1).button_text.setString(std::to_string(all.settings.masterVolume));
    }
}

void masterVolumeDown(All &all)
{
    if (all.settings.masterVolume != 0) {
        all.settings.masterVolume -= 10;
        all.menus.menusList.at(settingsFirstMenu).buttonsList.at(1).button_text.setString(std::to_string(all.settings.masterVolume));
    }
}

void musicVolumeUp(All &all)
{
    if (all.settings.musicVolume != 100) {
        all.settings.musicVolume += 10;
        all.menus.menusList.at(settingsFirstMenu).buttonsList.at(3).button_text.setString(std::to_string(all.settings.musicVolume));
        for (Music &music : all.assets.musics)
            music.music->setVolume(all.settings.musicVolume);
    }
}

void musicVolumeDown(All &all)
{
    if (all.settings.musicVolume != 0) {
        all.settings.musicVolume -= 10;
        all.menus.menusList.at(settingsFirstMenu).buttonsList.at(3).button_text.setString(std::to_string(all.settings.musicVolume));
        for (Music &music : all.assets.musics)
            music.music->setVolume(all.settings.musicVolume);
    }
}

void soundVolumeUp(All &all)
{
    if (all.settings.soundVolume != 100) {
        all.settings.soundVolume += 10;
        all.menus.menusList.at(settingsFirstMenu).buttonsList.at(5).button_text.setString(std::to_string(all.settings.soundVolume));
        for (Sound &sound : all.assets.sounds)
            sound.sound.setVolume(all.settings.soundVolume);
    }
}

void soundVolumeDown(All &all)
{
    if (all.settings.soundVolume != 0) {
        all.settings.soundVolume -= 10;
        all.menus.menusList.at(settingsFirstMenu).buttonsList.at(5).button_text.setString(std::to_string(all.settings.soundVolume));
        for (Sound &sound : all.assets.sounds)
            sound.sound.setVolume(all.settings.soundVolume);
    }
}

void noneAction(UN All &all)
{
    return;
}
