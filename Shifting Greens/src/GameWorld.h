#pragma once

#include <iostream>

#include "Ball.h"
#include "Player.h"
#include <memory>
#include <list>

class GameWorld {
private:
    SDL_Renderer* renderer;
    Player* player;
    std::list<std::unique_ptr<GameObject>> objects;
    const float interactDelay = 0.75f; // Tempo de espera para interação
    float interactTimer = 0.0f; // Temporizador de interação

public:
    GameWorld(SDL_Renderer* renderer, SDL_Texture* playerTexture);
    ~GameWorld();

    void Run(const float& dt, const Uint8* stat);
    void Render();
    void HandleEvents(SDL_Event& event, const Uint8* stat, const float& dt);
    bool InteractAction(const Uint8* stat);
};