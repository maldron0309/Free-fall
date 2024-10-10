#include <raylib.h>
#include "freefall.h"

FreeFall::FreeFall()
    : position1(0), position2(0), position3(0), velocity1(0), velocity2(0), velocity3(0), time(0) {}

FreeFall::~FreeFall() {}

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

    switch (currentMode)
    {
    case NO_AIR_RESISTANCE:
        velocity1 += gravity * deltaTime;
        position1 += velocity1 * deltaTime;
        velocity2 += gravity * deltaTime;
        position2 += velocity2 * deltaTime;
        velocity3 += gravity * deltaTime;
        position3 += velocity3 * deltaTime;
        break;

    case AIR_RESISTANCE:
        velocity1 += (gravity - 0.5f * velocity1) * deltaTime;
        position1 += velocity1 * deltaTime;
        velocity2 += (gravity - 0.5f * velocity2) * deltaTime;
        position2 += velocity2 * deltaTime;
        velocity3 += (gravity - 0.5f * velocity3) * deltaTime;
        position3 += velocity3 * deltaTime;
        break;

    case LINEAR_AIR_RESISTANCE:
        velocity1 += (gravity - 0.1f * velocity1) * deltaTime;
        position1 += velocity1 * deltaTime;
        velocity2 += (gravity - 0.1f * velocity2) * deltaTime;
        position2 += velocity2 * deltaTime;
        velocity3 += (gravity - 0.1f * velocity3) * deltaTime;
        position3 += velocity3 * deltaTime;
        break;

    case QUADRATIC_AIR_RESISTANCE:
        velocity1 += (gravity - 0.01f * velocity1 * velocity1) * deltaTime;
        position1 += velocity1 * deltaTime;
        velocity2 += (gravity - 0.01f * velocity2 * velocity2) * deltaTime;
        position2 += velocity2 * deltaTime;
        velocity3 += (gravity - 0.01f * velocity3 * velocity3) * deltaTime;
        position3 += velocity3 * deltaTime;
        break;
    }

    if (position1 > 1080 - 40)
    {
        position1 = 1080 - 40;
        velocity1 = 0;
    }
    if (position2 > 1080 - 40)
    {
        position2 = 1080 - 40;
        velocity2 = 0;
    }
    if (position3 > 1080 - 40)
    {
        position3 = 1080 - 40;
        velocity3 = 0;
    }
}

void FreeFall::Draw()
{
    DrawText("Free Fall Simulator", 10, 10, 20, BLACK);
    DrawText("By: Maldron", 10, 30, 20, BLACK);
    DrawText(TextFormat("Time: %.2f", time), 10, 50, 20, BLACK);

    DrawButtons(currentMode);

    int radius = 20;
    int baseY1 = (int)(position1);
    int baseY2 = (int)(position2);
    int baseY3 = (int)(position3);

    DrawCircle(640, baseY1, radius, RED);
    DrawText("10kg", 640 - 20, baseY1 - 10, 20, WHITE);

    DrawCircle(960, baseY2, radius, GREEN);
    DrawText("20kg", 960 - 20, baseY2 - 10, 20, WHITE);

    DrawCircle(1280, baseY3, radius, BLUE);
    DrawText("30kg", 1280 - 20, baseY3 - 10, 20, WHITE);
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
        if (CheckCollisionPointRec(mousePos, (Rectangle){10, 110, 320, 50}))
            currentMode = NO_AIR_RESISTANCE;
        else if (CheckCollisionPointRec(mousePos, (Rectangle){10, 170, 320, 50}))
            currentMode = AIR_RESISTANCE;
        else if (CheckCollisionPointRec(mousePos, (Rectangle){10, 230, 320, 50}))
            currentMode = LINEAR_AIR_RESISTANCE;
        else if (CheckCollisionPointRec(mousePos, (Rectangle){10, 290, 320, 50}))
            currentMode = QUADRATIC_AIR_RESISTANCE;
    }
}
