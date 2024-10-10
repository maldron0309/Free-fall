#include <raylib.h>
#include "freefall.h"

FreeFall::FreeFall()
{
}

FreeFall::~FreeFall()
{
}

void FreeFall::Init()
{
    constexpr int screenWidth = 1920;
    constexpr int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Free Fall Simulator");
    SetTargetFPS(60);
}

void FreeFall::Update()
{
    float deltaTime = GetFrameTime();
    time += deltaTime;
    position += velocity * deltaTime;
    velocity += gravity * deltaTime;
}

void FreeFall::Draw()
{
    DrawText("Free Fall Simulator", 10, 10, 20, BLACK);
    DrawText("By: Maldron", 10, 30, 20, BLACK);
    DrawText(TextFormat("Time: %.2f", time), 10, 50, 20, BLACK);
    DrawText(TextFormat("Position: %.2f", position), 10, 70, 20, BLACK);
    DrawText(TextFormat("Velocity: %.2f", velocity), 10, 90, 20, BLACK);

    DrawButtons(currentMode); 
}

void FreeFall::DrawButtons(Mode currentMode)
{
    Color noAirColor = currentMode == NO_AIR_RESISTANCE ? LIGHTGRAY : GRAY;
    Color airResColor = currentMode == AIR_RESISTANCE ? LIGHTGRAY : GRAY;
    Color linearResColor = currentMode == LINEAR_AIR_RESISTANCE ? LIGHTGRAY : GRAY;
    Color quadraticResColor = currentMode == QUADRATIC_AIR_RESISTANCE ? LIGHTGRAY : GRAY;

    DrawRectangle(10, 110, 320, 50, noAirColor);
    DrawText("No Air Resistance", 60, 120, 20, BLACK);

    DrawRectangle(10, 170, 320, 50, airResColor);
    DrawText("Air Resistance", 60, 185, 20, BLACK);

    DrawRectangle(10, 230, 320, 50, linearResColor);
    DrawText("Linear Air Resistance", 60, 245, 20, BLACK);

    DrawRectangle(10, 290, 320, 50, quadraticResColor);
    DrawText("Quadratic Air Resistance", 60, 305, 20, BLACK);
}


void FreeFall::HandleMouseInput(Mode &currentMode)
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        Vector2 mousePos = GetMousePosition();
        if (CheckCollisionPointRec(mousePos, (Rectangle){50, 50, 300, 50}))
            currentMode = NO_AIR_RESISTANCE;
        else if (CheckCollisionPointRec(mousePos, (Rectangle){50, 110, 300, 50}))
            currentMode = AIR_RESISTANCE;
        else if (CheckCollisionPointRec(mousePos, (Rectangle){50, 170, 300, 50}))
            currentMode = LINEAR_AIR_RESISTANCE;
        else if (CheckCollisionPointRec(mousePos, (Rectangle){50, 230, 300, 50}))
            currentMode = QUADRATIC_AIR_RESISTANCE;
    }
}
