#include "all.hpp"

void goToMainMenu(All &all)
{
    all.screen_id = mainMenu;
}

void playButtonFunction(All &all)
{
    if (all.screen_id != pauseMenu) {
        all.game.snake.head->rect.setPosition(sf::Vector2f(400, 400));
        all.game.snake.head->next = nullptr;
        srand(time(NULL));
        all.game.apple.apple.setPosition(20 * (rand() % 40), 20 * (rand() % 38) + 40);
        all.game.snake.head->moove = SOUTH;
        all.game.score = 0;
        all.game.score_txt.setString("SCORE : 0");
        all.game.round = 1;
        all.game.round_txt.setString("ROUND : 0");
    }
    all.menus.menusList.at(pauseMenu).actionButtonsList.at(3).button_text.setString(std::to_string(all.game.score));
    all.screen_id = playScreen;
}

void goToFirstSettingsMenu(All &all)
{
    all.screen_id = settingsFirstMenu;
}

void goToSecondSettingsMenu(All &all)
{
    all.screen_id = settingsSecondMenu;
}

void leaderButtonFunction(All &all)
{
    all.screen_id = leaderboardMenu;
}

void helpButtonFunction(All &all)
{
    all.screen_id = helpMenu;
}

void exitButtonFunction(All &all)
{
    all.window.close();
}

void masterVolumeUp(All &all)
{
    if (all.settings.masterVolume != 100) {
        all.settings.masterVolume += 10;
        all.menus.menusList.at(1).actionButtonsList.at(2).button_text.setString(std::to_string(all.settings.masterVolume));
    }
}

void masterVolumeDown(All &all)
{
    if (all.settings.masterVolume != 0) {
        all.settings.masterVolume -= 10;
        all.menus.menusList.at(1).actionButtonsList.at(2).button_text.setString(std::to_string(all.settings.masterVolume));
    }
}

void musicVolumeUp(All &all)
{
    if (all.settings.musicVolume != 100) {
        all.settings.musicVolume += 10;
        all.menus.menusList.at(1).actionButtonsList.at(6).button_text.setString(std::to_string(all.settings.musicVolume));
    }
}

void musicVolumeDown(All &all)
{
    if (all.settings.musicVolume != 0) {
        all.settings.musicVolume -= 10;
        all.menus.menusList.at(1).actionButtonsList.at(6).button_text.setString(std::to_string(all.settings.musicVolume));
    }
}

void soundVolumeUp(All &all)
{
    if (all.settings.soundVolume != 100) {
        all.settings.soundVolume += 10;
        all.menus.menusList.at(1).actionButtonsList.at(10).button_text.setString(std::to_string(all.settings.soundVolume));
    }
}

void soundVolumeDown(All &all)
{
    if (all.settings.soundVolume != 0) {
        all.settings.soundVolume -= 10;
        all.menus.menusList.at(1).actionButtonsList.at(10).button_text.setString(std::to_string(all.settings.soundVolume));
    }
}

void noneAction(UN All &all)
{
    return;
}
