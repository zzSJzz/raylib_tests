#ifndef ALIEN_HPP
#define ALIEN_HPP

#include <raylib.h>

class Alien
{
    public:
        Alien(int type, Vector2 position);
        void Update();
        void Draw();
        void static UnloadImages();
        int GetType();
        Image img;
        static Texture2D alienTexture[3];
        static bool txtStatusLoaded[3];
        int type;
        Vector2 position;
    private:

};
#endif