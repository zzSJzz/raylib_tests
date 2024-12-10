#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include <raylib.h>
#include "laser.hpp"
#include <vector>

class Spaceship
{
    public:
        Spaceship();
        ~Spaceship();
        void Draw();
        void MoveLeft();
        void MoveRight();
        void FireLaser();
        std::vector<Laser> lasers;

    private:
        /*Texture2D- Estrutura de dados representando uma imagem 2D, sendo usada na rendenização*/
        Texture2D image;
        Vector2 position;

};

#endif