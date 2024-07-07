#ifndef ASSETS_HPP_
    #define ASSETS_HPP_
    #include "font.hpp"
    #include "image.hpp"
    #include "music.hpp"
    #include "sound.hpp"
    #include <vector>

using namespace std;

class All;

class Assets {
    public:
        Assets(void);
        void displayImages(All &all);

        vector<Sound> sounds;
        vector<Image> images;
        vector<Music> musics;
        vector<Font> fonts;
    private:
};

#endif /* !ASSETS_HPP_ */
