#include "Interact.h"




bool Interact::checkCollision(float x, float y, float w, float h)
{
    if (this->circle.x + this->circle.radius < x) return false;
    else if (x + w < this->circle.x - this->circle.radius) return false;
    else if (this->circle.y + this->circle.radius < y) return false;
    else if (y + h < this->circle.y - this->circle.radius) return false;
    
    return true;
}