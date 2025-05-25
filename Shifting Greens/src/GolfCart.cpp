#include "GolfCart.h"

GolfCart::GolfCart(float x, float y, float width, float height, SDL_Color color,
                   float wInteract, float hInteract, vector speed)
    : Interactable(x, y, width, height, color, wInteract, hInteract), speed(speed)
{
}

void GolfCart::Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer, const SDL_Rect& camera)
{
    Square::Run(dt, stat, renderer, camera);
}

void GolfCart::Render(SDL_Renderer* renderer, const SDL_Rect& camera)
{
    Square::Render(renderer, camera);
}