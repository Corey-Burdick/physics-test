#include <line.h>

Line::Line(Vector2 pos1, Vector2 pos2) {
  this->pos1 = pos1;
  this->pos2 = pos2;
}

Line::~Line() {

}

void Line::update() {
  
}

void Line::draw() {
  DrawLineEx(pos1, pos2, 3.5, WHITE);
}

Vector2 Line::getNormalVector() {
  float dx = pos1.x - pos2.x;
  float dy = pos1.y - pos2.y;

  float len = std::sqrtf(dx * dx + dy * dy);  

  return Vector2{-dy/len, dx/len};
}
