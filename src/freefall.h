#pragma once

typedef enum
{
    NO_AIR_RESISTANCE,
    AIR_RESISTANCE,
    LINEAR_AIR_RESISTANCE,
    QUADRATIC_AIR_RESISTANCE
} Mode;

class FreeFall
{
public:
    FreeFall();
    ~FreeFall();

    void Init();
    void Update();
    void Draw();
    void DrawButtons(Mode currentMode);
    void HandleMouseInput(Mode &currentMode);

    Mode currentMode = NO_AIR_RESISTANCE; // Default mode

private:
    float gravity = 9.8f;
    float velocity = 0.0f;
    float position = 0.0f;
    float time = 0.0f;
};