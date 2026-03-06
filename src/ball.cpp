#include <ball.h>

Ball::Ball(Vector2 position, float radius) {
  this->position = position;
  this->radius = radius;
  velocity = (Vector2){0,0};
}

Ball::~Ball() {

}

void Ball::update(float gravity) {
  velocity.y += gravity;
  position.x += velocity.x;
  position.y += velocity.y;
}

void Ball::draw() {
  DrawCircleV(position, radius, WHITE);
}
