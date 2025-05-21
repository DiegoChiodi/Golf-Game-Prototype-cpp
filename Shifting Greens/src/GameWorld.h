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

<<<<<<< HEAD
    void Run(const float& dt);
    void Render();
    void HandleEvents(SDL_Event& event, const Uint8* stat, const float& dt);
=======
    void Run(float dt);
    void Render();
    void HandleEvents(SDL_Event& event);
>>>>>>> 4dfb594f4ef983018865a22bf328aee07b31894c
};