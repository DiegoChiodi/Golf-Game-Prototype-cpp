#include "Movel.h"

Movel::Movel(float x, float y, float width, float height, SDL_Color color, vector speed)
    : Square(x, y, width, height, color), speed(speed){}

void Movel::Run(float dt) { // Recebe dt como parâmetro
}

void Movel::HandleEvents(SDL_Event& event) {
    // Implementar lógica de eventos para o objeto Movel
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                position.y -= speed.y; // Mover para cima
                break;
            case SDLK_DOWN:
                position.y += speed.y; // Mover para baixo
                break;
            case SDLK_LEFT:
                position.x -= speed.x; // Mover para a esquerda
                break;
            case SDLK_RIGHT:
                position.x += speed.x; // Mover para a direita
                break;
            default:
                break;
        }
    }
}