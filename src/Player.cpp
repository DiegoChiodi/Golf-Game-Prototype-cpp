#include "Player.h"

Player::Player(float x, float y, float width, float height, SDL_Color color, vector speed)
    : Movel(x, y, width, height, color, speed) {}

void Player::HandleEvents(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                position.y -= speed.y;
                break;
            case SDLK_DOWN:
                position.y += speed.y;
                break;
            case SDLK_LEFT:
                position.x -= speed.x;
                break;
            case SDLK_RIGHT:
                position.x += speed.x;
                break;
        }
    }
}