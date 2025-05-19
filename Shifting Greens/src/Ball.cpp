#include "Ball.h"

Ball::Ball(float x, float y, float width, float height, SDL_Color color, vector speed)
    : Square(x, y, width, height, color), speed(speed){}
    {
        //Movel* movel = Movel(x, y, width, height, color, speed); 
    }

void Ball::Run(float dt) 
{ // Recebe dt como parâmetro
    this->position.x += (100.0f * dt);
    Square::ActualizeRect();
}

void Ball::Render(SDL_Renderer* renderer) 
{
    Movel::Render(renderer);
    //movel->Render(renderer);
}