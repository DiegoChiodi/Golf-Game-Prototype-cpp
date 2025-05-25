#include "BallDisplacement.h"

BallDisplacement::BallDisplacement(float x, float y, float width, float height, SDL_Color color, vector speed)
    : Movel(x, y, width, height, color, speed) {}

void BallDisplacement::Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer, const SDL_Rect& camera)
{
}

void BallDisplacement::Render(SDL_Renderer* renderer, const SDL_Rect& camera)
{
}