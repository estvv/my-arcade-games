#include "all.hpp"

void goToMainMenu(All &all)
{
    all.screen_id = mainMenu;
}

void goToPlay(All &all)
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
    all.menus.menusList.at(pauseMenu).buttonsList.at(1).button_text.setString(std::to_string(all.game.score));
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

void goToLeaderboard(All &all)
{
    all.screen_id = leaderboardMenu;
}

void goToHelp(All &all)
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
