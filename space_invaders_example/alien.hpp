#ifndef ALIEN_HPP
#define ALIEN_HPP

#include <raylib.h>

class Alien
{
    public:
        Alien(int type, Vector2 position);
        void Update();
        void Draw();
        int GetType();
        Texture2D image;
        static Texture2D ship1Texture;
        int type;
        Vector2 position;
    private:

};
#endif