#include "Camera.h"
#include "GlobalVariables.h"

Camera::Camera() {
    int const BASE_WIDTH = 640;
    int const BASE_HEIGHT = 360;
    this->viewBox = { 0, 0, BASE_WIDTH, BASE_HEIGHT };
}

void Camera::update(int targetX, int targetY, int mapW, int mapH) {
    int const BASE_WIDTH = 640;
    int const BASE_HEIGHT = 360;
    this->viewBox.x = targetX - BASE_WIDTH / 2;
    this->viewBox.y = targetY - BASE_HEIGHT / 2;

    if (this->viewBox.x < 0) {
        this->viewBox.x = 0;
    }

    if (this->viewBox.y < 0) {
        this->viewBox.y = 0;
    }

    if (this->viewBox.x + BASE_WIDTH > mapW) {
        this->viewBox.x = mapW - BASE_WIDTH;
    }

    if (this->viewBox.y + BASE_HEIGHT > mapH) {
        this->viewBox.y = mapH - BASE_HEIGHT;
    }
}

SDL_Rect Camera::getView() const {
    return this->viewBox;
}