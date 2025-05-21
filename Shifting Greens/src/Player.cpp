#include "Player.h"
<<<<<<< HEAD
#include <iostream>
=======
>>>>>>> 4dfb594f4ef983018865a22bf328aee07b31894c

Player::Player(float x, float y, float width, float height, SDL_Color color, vector speed)
    : Movel(x, y, width, height, color, speed) {}

<<<<<<< HEAD
void Player::HandleEvents(SDL_Event& event, const Uint8* stat, const float& dt) {
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
>>>>>>> 4dfb594f4ef983018865a22bf328aee07b31894c
    }
}