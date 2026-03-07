#pragma once

#include <iostream>
#include <raylib.h>
#include <ball.h>
#include <line.h>
#include <vector>

class Game {
private:
  void checkLineBallCollision();
  bool isDrawingLine;
  Vector2 lineStart;
public:
  int offset;
  int worldWidth;
  int worldHeight;
  float gravity;
  std::vector<Ball> activeBalls;
  std::vector<Line> activeLines;

  Game();
  ~Game();
  void update();
  void draw();

};
