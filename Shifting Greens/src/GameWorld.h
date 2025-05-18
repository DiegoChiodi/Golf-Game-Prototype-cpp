#pragma once

#include <iostream>

#include "Ball.h"
#include <memory>
#include <list>

class GameWorld {
private:
    SDL_Renderer* renderer;
    std::list<std::unique_ptr<GameObject>> objects;
public:
    GameWorld(SDL_Renderer* renderer);
    ~GameWorld();

    void Run(float dt);
    void Render();
    void HandleEvents(SDL_Event& event);
};