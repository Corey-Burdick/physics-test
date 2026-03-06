#pragma once

#include <raylib.h>

class Game {
private:

public:
  int offset;
  int worldWidth;
  int worldHeight;

  Game();
  ~Game();
  void update();
  void draw();

};
