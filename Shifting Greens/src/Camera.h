#pragma once
#include <SDL2/SDL.h>

class Camera{
private:
    SDL_Rect viewBox;
public:
    Camera();

    void update(int targetX, int targetY, int mapW, int mapH);
    SDL_Rect getView() const;
};