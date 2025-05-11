#pragma once

#include <SDL2/SDL.h>
#include <memory>

#include "GameObject.h"
#include "Circle.h"


class GameWorld {
private:
    std::list<std::unique_ptr<GameObject>> objects;
public:
    GameWorld();
    ~GameWorld();

    void Initialize();
    void Update();
    void Render()
    {
        // Render game objects
        for (auto& object : objects) {
            object->Render(renderer);
        }
    }
    void HandleInput(SDL_Event& event);
    void Cleanup();
}