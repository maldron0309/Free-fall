#include <raylib.h>
#include "freefall.h"

int main()
{
    FreeFall freeFall;
    freeFall.Init();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        freeFall.Update();
        ClearBackground(WHITE);

        freeFall.Draw();
        freeFall.DrawButtons(freeFall.currentMode);
        freeFall.HandleMouseInput(freeFall.currentMode);


        EndDrawing();
    }

    CloseWindow();
}