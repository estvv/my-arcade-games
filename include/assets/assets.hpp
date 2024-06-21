#ifndef ASSETS_HPP_
    #define ASSETS_HPP_
    #include "font.hpp"
    #include "image.hpp"
    #include "music.hpp"
    #include "sound.hpp"
    #include <vector>

class All;

class Assets {
    public:
        Assets(void);
        void displayImages(All &all);

        std::vector<Sound> sounds;
        std::vector<Image> images;
        std::vector<Music> musics;
        std::vector<Font> fonts;
    private:
};

#endif /* !ASSETS_HPP_ */
