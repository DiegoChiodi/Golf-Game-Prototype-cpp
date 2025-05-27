#pragma once

#include <iostream>

#include "Ball.h"
#include "Player.h"
#include <memory>
#include <list>
#include "TextureManager.h"
#include "Camera.h"
#include "Hole.h"

class GameWorld {
private:
    SDL_Renderer* renderer;
    Player* player;
    std::list<std::unique_ptr<GameObject>> objects;
    const float interactDelay = 0.75f; // Tempo de espera para interação
    float interactTimer = 0.0f; // Temporizador de interação
    TextureManager* textureManager;
    Camera camera;
    GameObject* viewTarget; // Ponto de destino da câmera
    Ball* ball;
public:
    GameWorld(SDL_Renderer* renderer, TextureManager* textureManager);
    ~GameWorld();

    void Run(const float& dt, const Uint8* stat);
    bool InteractAction(const Uint8* stat);
    void Colliders(const float& dt, const Uint8* stat, GameObject* object, GameObject* other);
};