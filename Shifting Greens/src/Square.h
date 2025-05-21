#pragma once

#include "GameObject.h"

class Square : public GameObject {
protected:
    SDL_Rect rect;
    SDL_Color color;
public:
    Square(float x, float y, float width, float height, SDL_Color color);
    ~Square() override;

<<<<<<< HEAD
    void Run(const float& dt) override;
=======
    void Run(float dt) override;
>>>>>>> 4dfb594f4ef983018865a22bf328aee07b31894c

    virtual void ActualizeRect();
    void Render(SDL_Renderer* renderer) override;
    bool CheckCollision(point otherPosition, float otherWidth, float otherHeight) const;
    float GetWidth() const { return width; }
    float GetHeight() const { return height; }
};