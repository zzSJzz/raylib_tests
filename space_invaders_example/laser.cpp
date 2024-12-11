#include "laser.hpp"
#include <iostream>

//Crio a classe laser que tem como parametro Vector(x, y) position e o speed
Laser::Laser(Vector2 position, int speed)
{
    this -> position = position;
    this -> speed = speed;
    active = true;
}

void Laser::Draw()
{
    if (active)
        //Dentro das chaves eu seto a cor (padrao RGBA lpha - Transparencia - opaco)
        DrawRectangle(position.x, position.y, 4, 15,{0, 0, 255, 255});
}

void Laser::Update()
{   
    position.y -= speed;
    if (active)
        if(position.y > GetScreenHeight() || position.y < 0)
        {
            active = false;
        }
}