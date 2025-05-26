#include "Hole.h"

Hole::Hole(float x, float y, float width, float height, SDL_Color color, Ball* ball)
    : Square(x, y, width, height, color), ball(ball) {
    strokes = 0;
    isCompleted = false;
}

Ball* Hole::GetBall() const {
    return ball;
}

int Hole::GetStrokes() const {
    return strokes;
}

void Hole::IncrementStrokes() {
    strokes++;
}

void Hole::ResetStrokes() {
    strokes = 0;
}

bool Hole::IsCompleted() const {
    return isCompleted;
}

void Hole::SetCompleted(bool completed) {
    isCompleted = completed;
}