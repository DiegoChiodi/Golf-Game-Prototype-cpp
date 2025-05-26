#include "BallPreview.h"

BallPreview::BallPreview(float x, float y, float width, float height, SDL_Color color, vector speed)
    : Movel(x, y, width, height, color, speed) {}

void BallPreview::Render(SDL_Renderer* renderer, const SDL_Rect& camera)
{
    
    circleRGBA(renderer, static_cast<Sint16>(position.x), static_cast<Sint16>(position.y), 
               static_cast<Sint16>(width * 10), color.r, color.g, color.b, color.a);    
    Movel::Render(renderer, camera);
}