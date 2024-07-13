#ifndef MENUS_HPP_
    #define MENUS_HPP_
    #include <vector>
    #include "buttons.hpp"
    #include "enum.hpp"
    #include "colors.hpp"
    #include "assets.hpp"

using namespace std;

class Menu {
    public:
        Menu(sf::RenderWindow &window);
        void manageMenusEvent(All &all);
        void displayMenus(void);
        void updateMenus(Colors colors);
        void inputKey(All &all);
        void inputClickPressed(All &all);
        void inputClickReleased(All &all);

        vector<toggledButtons> toggledButtonsList;
        vector<actionButtons> actionButtonsList;
        vector<Buttons> buttonsList;
        sf::RenderWindow &window;
    private:
};

class Menus {
    public:
        Menus(All *all, sf::RenderWindow &window);
        void initMain(All &all);
        void initSettings(All &all);
        void initLeaderboard(All &all);
        void initDead(All &all);
        void initPause(All &all);
        void initHelp(All &all);
        void initChoosingGame(All &all);
        void updateMenusColors(MenusColors menusColors);

        vector<Menu> menusList;
    private:
};

#endif /* !MENUS_HPP_ */
