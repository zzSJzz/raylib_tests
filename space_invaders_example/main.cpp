#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.hpp"


int main()
{
    Color grey = {29, 29, 27, 255};
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth, windowHeight, "Space Invaders Interface");

    SetTargetFPS(60);

    // Spaceship spaceship;
    Game game;

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(grey);
        // spaceship.Draw();
        game.Draw();

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}