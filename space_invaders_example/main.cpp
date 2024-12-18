#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.hpp"
// #include "obstacle.hpp"
// #include "laser.hpp"
// #include "alien.hpp"

int main()
{
    Color grey = {29, 29, 27, 255};
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth, windowHeight, "Space Invaders Interface");

    SetTargetFPS(60);

    // Spaceship spaceship;
    Game game;
    // Laser laser = Laser({100, 100}, 7);  - Não é necessário pois declaro na lib spaceship.hpp
    // Obstacle obstacle = Obstacle({100,100});

    // Alien alien = Alien(2, {100, 100});

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(grey);
        // spaceship.Draw();
        game.Draw();
        game.HandleInput();
        game.Update();
        // laser.Draw();
        // laser.Update();
        // alien.Draw();
        
        // obstacle.Draw();
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}