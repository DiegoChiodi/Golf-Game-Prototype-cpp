#pragma once
#include "Square.h"
#include "Ball.h"

class Hole : public Square {
private:
    Ball* ball;
    int strokes = 0;
    bool isCompleted = false;

public:
    Hole(float x, float y, float width, float height, SDL_Color color, Ball* ball);

    Ball* GetBall() const; // 🔧 Adicionada declaração
    int GetStrokes() const;           // Apenas declaração
    void IncrementStrokes();          // Apenas declaração
    void ResetStrokes();              // Apenas declaração
    bool IsCompleted() const;         // Apenas declaração
    void SetCompleted(bool completed);// Apenas declaração
};
