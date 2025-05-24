#include "Ball.h"

Ball::Ball(float x, float y, float width, float height, SDL_Color color, vector speed, 
           float wInteract, float hInteract)
           : Interactable(x, y, width, height, color, speed, wInteract, hInteract){}

void Ball::Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer) 
{ // Recebe dt como parâmetro
    this->position.x += (speed.x * dt);
    Square::ActualizeRect();
    
    if (ballDisplacement) {
        ballDisplacement->Run(dt, stat, renderer);
    }
    
    Render(renderer);
}

void Ball::Render(SDL_Renderer* renderer) 
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_Rect rectCollisor = { static_cast<int>(position.x - (wInteract / 2) + width / 2), static_cast<int>(position.y - (hInteract / 2) + height / 2), 
        static_cast<int>(wInteract), static_cast<int>(hInteract) };
    SDL_RenderFillRect(renderer, &rectCollisor);

    Square::Render(renderer);
}