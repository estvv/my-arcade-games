#ifndef ENUM_HPP_
    #define ENUM_HPP_
    #define UN __attribute__((unused))
    #define screenCounter 14
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
    choosingSnakeGameMenu,
    choosingBreakoutGameMenu,
    choosingBubbleShooterGameMenu,
    choosingTetrisGameMenu,
    snakePlayScreen,
    breakoutPlayScreen,
    bubbleShooterPlayScreen,
    tetrisPlayScreen
};

enum buttonState {
    isNone,
    mouseHover,
    mouseClicked,
    isDisabled
};

enum game {
    snake,
    breakout,
    bubbleShooter,
    tetris
};

#endif /* !ENUM_HPP_ */
