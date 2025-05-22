#include "Ball.h"

Ball::Ball(float x, float y, float width, float height, SDL_Color color, vector speed, 
           float wInteract, float hInteract)
           : Interactable(x, y, width, height, color, speed, wInteract, hInteract){}

void Ball::Run(const float& dt) 
{ // Recebe dt como parâmetro
    this->position.x += (speed.x * dt);
    Square::ActualizeRect();
    
    if (ballDisplacement) {
        ballDisplacement->Run(dt);
    }
}

void Ball::Render(SDL_Renderer* renderer) 
{
    if (ballDisplacement) {
        ballDisplacement->Render(renderer);
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_Rect rectCollisor = { static_cast<int>(position.x - (wInteract / 2) + width / 2), static_cast<int>(position.y - (hInteract / 2) + height / 2), 
        static_cast<int>(wInteract), static_cast<int>(hInteract) };
    SDL_RenderFillRect(renderer, &rectCollisor);

    Square::Render(renderer);
}

void Ball::HandleEvents(SDL_Event& event, const  Uint8* stat, const float& dt) 
{
    if (ballDisplacement) {
        ballDisplacement->HandleEvents(event, stat, dt);
    }
}