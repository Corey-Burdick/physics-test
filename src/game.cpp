#include <game.h>

Game::Game() {
  offset = 25;
  worldWidth = GetScreenWidth() - 2*offset;
  worldHeight = GetScreenHeight() - 2*offset;
  gravity = 0.25f;
  activeLines.push_back(Line(Vector2{600, 500}, Vector2{750, 700}));
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

  checkLineBallCollision();
  
}

void Game::draw() {
  //DrawRectangleLinesEx((Rectangle){offset, offset, worldWidth, worldHeight}, 5, WHITE);
  std::cout << "Balls: " << activeBalls.size() << std::endl;

  for (auto& b : activeBalls) {
    b.draw();
  }

  for (auto& l : activeLines) {
    l.draw();
  }
}

void Game::checkLineBallCollision() {
 for (auto& b : activeBalls) {
    for (auto& l : activeLines) {
      if (std::fabs(l.getNormalVector().x * (b.position.x - l.pos1.x) + l.getNormalVector().y * (b.position.y - l.pos1.y)) < 10) {
        float minX = std::min(l.pos1.x, l.pos2.x);
        float maxX = std::max(l.pos1.x, l.pos2.x);
        if (b.position.x >= minX && b.position.x <= maxX) {
          std::cout << "Contact." << std::endl;
          Vector2 TempV = b.velocity;
          b.velocity.x = b.velocity.x - 2 * (b.velocity.x * l.getNormalVector().x + b.velocity.y * l.getNormalVector().y) * l.getNormalVector().x;
          b.velocity.y = TempV.y - 2 * (TempV.x * l.getNormalVector().x + b.velocity.y * l.getNormalVector().y) * l.getNormalVector().y;
        }
      } 
    }
  }
}
