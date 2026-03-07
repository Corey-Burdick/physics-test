#include <ball.h>

Ball::Ball(Vector2 position, float radius) {
  this->position = position;
  this->radius = radius;
  velocity = Vector2{0,0};
  elasticity = 0.95f;
  colliding = false;
}

Ball::~Ball() {

}

void Ball::update(float gravity) {
  if (!colliding) {
    velocity.y += gravity;
  }
  position.x += velocity.x;
  position.y += velocity.y;

  if (velocity.x * velocity.x + velocity.y * velocity.y >= 100) {
    float speed = std::sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);
    velocity.x *= 10 / speed;
    velocity.y *= 10 / speed;
  }
}

void Ball::draw() {
  DrawCircleV(position, radius, WHITE);
}
