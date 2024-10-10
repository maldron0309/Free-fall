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
    const float gravity = 9.8f;
    float time = 0.0f;
    float height = 1000.0f;

    float position1 = 0.0f;
    float position2 = 0.0f;
    float position3 = 0.0f;
    float velocity1 = 0.0f;
    float velocity2 = 0.0f;
    float velocity3 = 0.0f;
};
