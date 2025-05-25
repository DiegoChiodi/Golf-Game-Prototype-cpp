#include "Ball.h"

Ball::Ball(float x, float y, float width, float height, SDL_Color color, 
           float wInteract, float hInteract, vector speed)
    : Interactable(x, y, width, height, color, wInteract, hInteract), speed(speed)
    {}

void Ball::Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer, const SDL_Rect& camera) 
{
    Square::Run(dt, stat, renderer, camera);
    
    if (ballDisplacement) {
        ballDisplacement->Run(dt, stat, renderer, camera);
    }
}

void Ball::Render(SDL_Renderer* renderer, const SDL_Rect& camera) 
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_Rect rectCollisor = { static_cast<int>(position.x - (wInteract / 2) + width / 2), static_cast<int>(position.y - (hInteract / 2) + height / 2), 
        static_cast<int>(wInteract), static_cast<int>(hInteract) };
    
    SDL_Rect renderRectCollisor;
    renderRectCollisor.x = rectCollisor.x - camera.x;
    renderRectCollisor.y = rectCollisor.y - camera.y;
    renderRectCollisor.w = rectCollisor.w;
    renderRectCollisor.h = rectCollisor.h;

    SDL_RenderFillRect(renderer, &renderRectCollisor);

    Square::Render(renderer, camera);
}