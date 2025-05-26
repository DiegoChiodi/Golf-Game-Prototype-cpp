#include "Camera.h"
#include "GlobalVariables.h"

Camera::Camera() {
    this->viewBox = { 0, 0, Global::LOGICAL_WIDTH, Global::LOGICAL_HEIGHT };
}
void Camera::update(int targetX, int targetY, int mapW, int mapH) {
    float lerp = 0.1f; // Lerp factor

    // Calculate target positions for the camera center
    int targetViewX = targetX - Global::LOGICAL_WIDTH / 2;
    int targetViewY = targetY - Global::LOGICAL_HEIGHT / 2;

    // Apply linear interpolation to smooth camera movement
    this->viewBox.x += static_cast<int>((targetViewX - this->viewBox.x) * lerp);
    this->viewBox.y += static_cast<int>((targetViewY - this->viewBox.y) * lerp);

    if (this->viewBox.x < 0) {
        this->viewBox.x = 0;
    }

    if (this->viewBox.y < 0) {
        this->viewBox.y = 0;
    }

    if (this->viewBox.x + Global::LOGICAL_WIDTH > mapW) {
        this->viewBox.x = mapW - Global::LOGICAL_WIDTH;
    }

    if (this->viewBox.y + Global::LOGICAL_HEIGHT > mapH) {
        this->viewBox.y = mapH - Global::LOGICAL_HEIGHT;
    }
}

SDL_Rect Camera::getView() const {
    return this->viewBox;
}

void Camera::setView(SDL_Rect& viewClaim) {
    this->viewBox = viewClaim;
}