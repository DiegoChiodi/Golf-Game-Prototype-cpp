#pragma once

struct circle {
    float x, y, radius;
};

class Interact {
protected:
    circle circle;
public:
    Interact(float x, float y, float radius);
    ~Interact();
    
    bool Run(float x, float y, float w, float h);
    
    bool checkCollision(float x, float y, float w, float h);

    void setPosition(float x, float y);
    void setRadius(float radius);
};