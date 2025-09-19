#include "GolfCartMoviment.h"

GolfCartMoviment::GolfCartMoviment(float x, float y, float width, float height, SDL_Color color, 
                                   vector speed)
    : Movel(x, y, width, height, color, speed)
{
}

void GolfCartMoviment::Render(SDL_Renderer* renderer, const SDL_Rect& camera)
{
    Movel::Render(renderer, camera);
}

void GolfCartMoviment::HandleEvents(const Uint8* stat, const float& dt)
{
    
}

vector GolfCartMoviment::Mover(float anguloGraus, vector speed, const float& dt) {
    float anguloRad = anguloGraus * (M_PI / 180.0f);
    float dx = cos(anguloRad) * speed.x * dt;
    float dy = sin(anguloRad) * speed.y * dt;       
    return {dx, dy};
}
