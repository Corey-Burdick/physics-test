#pragma once

#include <raylib.h>
#include <cmath>

class Ball{
private:

public:
  Vector2 position;
  Vector2 velocity;
  float radius;
  float elasticity;
  bool colliding;
  int age;

  Ball(Vector2 position, float radius);
  ~Ball();
  void update(float gravity);
  void draw();
};
