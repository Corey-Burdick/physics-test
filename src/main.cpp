#include <raylib.h>
#include <game.h>

int main() {

  InitWindow(1000, 1000, "Test");
  SetTargetFPS(60);

  Game game;

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLUE);

    game.update();
    game.draw();

    EndDrawing();
  }

  return 0;
}
