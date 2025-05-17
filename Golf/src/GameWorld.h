#pragma once

#include <iostream>

#include "Ball.h"

class GameWorld {
private:
    SDL_Renderer* renderer;
    std::list<std::unique_ptr<GameObject>> objects;
public:
    GameWorld(SDL_Renderer* renderer);
    ~GameWorld();

    void Run();
    void Render();
    void Cleanup();
};