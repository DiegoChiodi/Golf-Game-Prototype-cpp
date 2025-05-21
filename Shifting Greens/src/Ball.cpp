#include "Ball.h"

Ball::Ball(float x, float y, float width, float height, SDL_Color color, vector speed)
    : Movel(x, y, width, height, color, speed){}

<<<<<<< HEAD
void Ball::Run(const float& dt) 
=======
void Ball::Run(float dt) 
>>>>>>> 4dfb594f4ef983018865a22bf328aee07b31894c
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

<<<<<<< HEAD
void Ball::HandleEvents(SDL_Event& event, const  Uint8* stat, const float& dt) 
{
    if (ballDisplacement) {
        ballDisplacement->HandleEvents(event, stat, dt);
=======
void Ball::HandleEvents(SDL_Event& event) 
{
    if (ballDisplacement) {
        ballDisplacement->HandleEvents(event);
>>>>>>> 4dfb594f4ef983018865a22bf328aee07b31894c
    }
}