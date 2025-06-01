#include "BallPreview.h"

BallPreview::BallPreview(float x, float y, float width, float height, SDL_Color color, vector speed)
    : Movel(x, y, width, height, color, speed) {}

void BallPreview::Render(SDL_Renderer* renderer, const SDL_Rect& camera)
{
    circleRGBA(
        renderer,
        static_cast<Sint16>(position.x - camera.x + width / 2),
        static_cast<Sint16>(position.y - camera.y + height / 2),
        static_cast<Sint16>(widthCircle),
        255, 255 , 255, 255
    );

    Movel::Render(renderer, camera);
}

void BallPreview::Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer, const SDL_Rect& camera)
{
    Square::Run(dt, stat, renderer, camera);
}