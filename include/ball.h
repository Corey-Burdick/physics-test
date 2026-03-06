#pragma once

#include <raylib.h>

class Ball{
private:

public:
  Vector2 position;
  Vector2 velocity;
  float radius;
  float elasticity;

  Ball(Vector2 position, float radius);
  ~Ball();
  void update(float gravity);
  void draw();
};
