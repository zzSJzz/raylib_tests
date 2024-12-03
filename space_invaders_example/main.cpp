#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Color grey = {29, 29, 27, 255};
    int windowWidth = 1024;
    int windowHeight = 600;

    InitWindow(windowWidth, windowHeight, "Space Invaders Interface");

    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(grey);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}