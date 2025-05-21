#include "BallDisplacement.h"

BallDisplacement::BallDisplacement(float x, float y, float width, float height, SDL_Color color, vector speed)
    : Movel(x, y, width, height, color, speed) {}

void BallDisplacement::Run(const float& dt)
{
}

void BallDisplacement::Render(SDL_Renderer* renderer)
{
    Movel::Render(renderer);
}

void BallDisplacement::HandleEvents(SDL_Event& event, const  Uint8* stat, const float& dt)
{
    if (stat[SDL_SCANCODE_UP]) {
        position.y -= speed.y * dt;
    }
    if (stat[SDL_SCANCODE_DOWN]) {
        position.y += speed.y * dt;
    }
    if (stat[SDL_SCANCODE_LEFT]) {
        position.x -= speed.x * dt;
    }
    if (stat[SDL_SCANCODE_RIGHT]) {
        position.x += speed.x * dt;
    }
}