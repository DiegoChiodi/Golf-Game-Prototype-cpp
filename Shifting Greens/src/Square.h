#pragma once

#include "GameObject.h"

class Square : public GameObject {
protected:
    SDL_Rect rect;
    SDL_Color color;
public:
    Square(float x, float y, float width, float height, SDL_Color color);
    ~Square() override;

    void Run(float dt) override { /* Implementar lógica de atualização do quadrado */ }

    virtual void ActualizeRect();
    void Render(SDL_Renderer* renderer) override;
    bool CheckCollision(point otherPosition, float otherWidth, float otherHeight) const;
    float GetWidth() const { return width; }
    float GetHeight() const { return height; }
};