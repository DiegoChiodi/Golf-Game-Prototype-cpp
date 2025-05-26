#include "Interactable.h"

Interactable::Interactable(float x, float y, float width, float height, SDL_Color color,
                           float wInteract, float hInteract)
    : Square(x, y, width, height, color), wInteract(wInteract), hInteract(hInteract) {}

void Interactable::RenderCollisor(SDL_Renderer* renderer, const SDL_Rect& camera)
{
    SDL_SetRenderDrawColor(renderer, 255, 30, 30, 255);
    SDL_Rect rectCollisor = { static_cast<int>(position.x - (wInteract / 2) + width / 2), static_cast<int>(position.y - (hInteract / 2) + height / 2), 
        static_cast<int>(wInteract), static_cast<int>(hInteract) };
    
    SDL_Rect renderRectCollisor;
    renderRectCollisor.x = rectCollisor.x - camera.x;
    renderRectCollisor.y = rectCollisor.y - camera.y;
    renderRectCollisor.w = rectCollisor.w;
    renderRectCollisor.h = rectCollisor.h;

    SDL_RenderFillRect(renderer, &renderRectCollisor);
}