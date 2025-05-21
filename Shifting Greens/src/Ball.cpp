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
    Square::Render(renderer);
}

void Ball::HandleEvents(SDL_Event& event, const  Uint8* stat, const float& dt) 
{
    if (ballDisplacement) {
        ballDisplacement->HandleEvents(event, stat, dt);
    }
}