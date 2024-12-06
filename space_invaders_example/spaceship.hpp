#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include <raylib.h>

class Spaceship
{
    public:
        Spaceship();
        ~Spaceship();
        void Draw();
        void MoveLeft();
        void MoveRight();
        void FireLaser();

    private:
        /*Texture2D- Estrutura de dados representando uma imagem 2D, sendo usada na rendenização*/
        Texture2D image;
        Vector2 position;

};

#endif