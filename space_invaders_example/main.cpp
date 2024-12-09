#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.hpp"
#include "laser.hpp"

int main()
{
    Color grey = {29, 29, 27, 255};
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth, windowHeight, "Space Invaders Interface");

    SetTargetFPS(60);

    // Spaceship spaceship;
    Game game;
    Laser laser = Laser({100, 100}, 7);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(grey);
        // spaceship.Draw();
        game.Draw();
        game.HandleInput();

        laser.Draw();
        laser.Update();
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}