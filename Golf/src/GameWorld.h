#pragma once

#include <memory>
#include <list>
#include <iostream>

#include "Circle.h"


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