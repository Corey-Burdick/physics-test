#pragma once

#include <iostream>
#include <raylib.h>
#include <ball.h>
#include <vector>

class Game {
private:

public:
  int offset;
  int worldWidth;
  int worldHeight;
  float gravity;
  std::vector<Ball> activeBalls;

  Game();
  ~Game();
  void update();
  void draw();

};
