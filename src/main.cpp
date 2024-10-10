#include <raylib.h>

int main() 
{
    
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "Free Fall");
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {        
        BeginDrawing();

        EndDrawing();
    }
    
    CloseWindow();
}