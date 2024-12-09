#ifndef LASER_HPP
#define LASER_HPP

#include <raylib.h>

class Laser
{
    public:
        Laser(Vector2 position, int speed);
        void Update();
        void Draw();
        bool active;
    private:
        Vector2 position;
        int speed;

};
#endif