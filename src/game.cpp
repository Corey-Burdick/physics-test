#include <game.h>

Game::Game() {
  offset = 25;
  worldWidth = GetScreenWidth() - 2*offset;
  worldHeight = GetScreenHeight() - 2*offset;
  gravity = 0.25f;
}

Game::~Game() {

}

void Game::update() {
  if (IsMouseButtonPressed(0)) {
    activeBalls.push_back(Ball(GetMousePosition(), 5)); 
  }

  for (auto& b : activeBalls) {
    b.update(gravity);
  }
}

void Game::draw() {
  DrawRectangleLinesEx((Rectangle){offset, offset, worldWidth, worldHeight}, 5, WHITE);
  std::cout << "Balls: " << activeBalls.size() << std::endl;

  for (auto& b : activeBalls) {
    b.draw();
  }
}
