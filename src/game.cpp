#include <game.h>

Game::Game() {
  offset = 25;
  worldWidth = GetScreenWidth() - 2*offset;
  worldHeight = GetScreenHeight() - 2*offset;
  gravity = 0.25f;
  activeLines.push_back(Line(Vector2{0, GetScreenHeight()}, Vector2{GetScreenWidth(), GetScreenHeight()}));
  activeLines.push_back(Line(Vector2{0, 0}, Vector2{0, GetScreenHeight()}));
  activeLines.push_back(Line(Vector2{GetScreenWidth(), 0}, Vector2{GetScreenWidth(), GetScreenHeight()}));
  activeLines.push_back(Line(Vector2{250, 250}, Vector2{600, 600}));
  isDrawingLine = false;
  
}

Game::~Game() {

}

void Game::update() {
  if (IsMouseButtonDown(0)) {
    activeBalls.push_back(Ball(GetMousePosition(), 5)); 
  }
  if (IsMouseButtonPressed(1)) {
    if (isDrawingLine == false) {
      isDrawingLine = true;
      lineStart = GetMousePosition();
    } else {
      activeLines.push_back(Line(lineStart, GetMousePosition()));
      isDrawingLine = false;
    }
  } 

  for (auto& b : activeBalls) {
    b.update(gravity);
  }

  checkLineBallCollision();
  
}

void Game::draw() {
  //DrawRectangleLinesEx((Rectangle){offset, offset, worldWidth, worldHeight}, 5, WHITE);
  //std::cout << "Balls: " << activeBalls.size() << std::endl;

  for (auto& b : activeBalls) {
    b.draw();
  }

  for (auto& l : activeLines) {
    l.draw();
  }

  if (isDrawingLine) {
    DrawLineV(lineStart, GetMousePosition(), GREEN);
  }

  DrawFPS(10, 10);
}

void Game::checkLineBallCollision() {
 for (auto& b : activeBalls) {
    b.colliding = false;
    for (auto& l : activeLines) {
      if (std::fabs(l.getNormalVector().x * (b.position.x - l.pos1.x) + l.getNormalVector().y * (b.position.y - l.pos1.y)) < 10) {
        float minX = std::min(l.pos1.x, l.pos2.x) - 20;
        float maxX = std::max(l.pos1.x, l.pos2.x) + 20;
        if (b.position.x >= minX && b.position.x <= maxX) {
          b.colliding = true;
          bool posSign = (l.getNormalVector().x * (b.position.x - l.pos1.x) + l.getNormalVector().y * (b.position.y - l.pos1.y)) < 0;
          bool velSign = (l.getNormalVector().x * b.velocity.x + l.getNormalVector().y * b.velocity.y) < 0;
          if (posSign != velSign) {
            //std::cout << "Contact." << std::endl;
            Vector2 TempV = b.velocity;
            b.velocity.x = b.velocity.x - 2 * (b.velocity.x * l.getNormalVector().x + b.velocity.y * l.getNormalVector().y) * l.getNormalVector().x;
            b.velocity.y = TempV.y - 2 * (TempV.x * l.getNormalVector().x + b.velocity.y * l.getNormalVector().y) * l.getNormalVector().y;
            b.velocity.x *= b.elasticity;
            b.velocity.y *= b.elasticity;
          }
        }
      } 
    }
  }
}
