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
public:
    GameWorld(SDL_Renderer* renderer);
    ~GameWorld();

    void Run(const float& dt, const Uint8* stat);
    void Render();
    void HandleEvents(SDL_Event& event, const Uint8* stat, const float& dt);
    bool InteractAction(const Uint8* stat);
};