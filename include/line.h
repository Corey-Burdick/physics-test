#pragma once

#include <raylib.h>
#include <cmath>

class Line {
private:

public:
  Vector2 pos1;
  Vector2 pos2;

  Line(Vector2 pos1, Vector2 pos2);
  ~Line();
  void update();
  void draw();
  Vector2 getNormalVector();
};
