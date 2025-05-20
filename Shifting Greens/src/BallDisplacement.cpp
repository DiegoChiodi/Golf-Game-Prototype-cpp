#include "BallDisplacement.h"

BallDisplacement::BallDisplacement(float x, float y, float width, float height, SDL_Color color, vector speed)
    : Movel(x, y, width, height, color, speed) {}

void BallDisplacement::Run(float dt)
{
}

void BallDisplacement::Render(SDL_Renderer* renderer)
{
    Movel::Render(renderer);
}

void BallDisplacement::HandleEvents(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                position.y -= 10;
                break;
            case SDLK_DOWN:
                position.y += 10;
                break;
            case SDLK_LEFT:
                position.x -= 10;
                break;
            case SDLK_RIGHT:
                position.x += 10;
                break;
        }
    }
}