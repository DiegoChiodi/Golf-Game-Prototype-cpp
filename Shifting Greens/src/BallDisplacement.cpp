#include "BallDisplacement.h"

BallDisplacement::BallDisplacement(float x, float y, float width, float height, SDL_Color color, vector speed)
    : Movel(x, y, width, height, color, speed) {}

<<<<<<< HEAD
void BallDisplacement::Run(const float& dt)
=======
void BallDisplacement::Run(float dt)
>>>>>>> 4dfb594f4ef983018865a22bf328aee07b31894c
{
}

void BallDisplacement::Render(SDL_Renderer* renderer)
{
    Movel::Render(renderer);
}

<<<<<<< HEAD
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
=======
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
>>>>>>> 4dfb594f4ef983018865a22bf328aee07b31894c
    }
}