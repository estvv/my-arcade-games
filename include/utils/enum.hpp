#ifndef ENUM_HPP_
    #define ENUM_HPP_
    #define UN __attribute__((unused))
    #define SOUND_CLICK 0
    #define SOUND_HOVER 1
    #define SOUND_INPUT 2
    #define SOUND_ESCAPE 3
    #define SOUND_DEATH 4
    #define SOUND_APPLE 5

enum screens {
    mainMenu,
    settingsFirstMenu,
    settingsSecondMenu,
    leaderboardMenu,
    deadMenu,
    pauseMenu,
    helpMenu,
    playScreen
};

enum buttonState {
    isNone,
    mouseHover,
    mouseClicked,
    isDisabled
};

#endif /* !ENUM_HPP_ */
