#pragma once

#include <SDL2/SDL.h>
#include <memory>
#include <list>

#include "GameObject.h"
#include "Circle.h"


class GameWorld {
private:
    SDL_Renderer* renderer;
    std::list<std::unique_ptr<GameObject>> objects;
public:
    GameWorld(SDL_Renderer* renderer);
    ~GameWorld();

    void Initialize();
    void Run();
    void Render();
    void Cleanup();
};