#include <game.h>

Game::Game() {
  offset = 25;
  worldWidth = GetScreenWidth() - 2*offset;
  worldHeight = GetScreenHeight() - 2*offset;
}

Game::~Game() {

}

void Game::update() {

}

void Game::draw() {
  DrawRectangleLinesEx((Rectangle){offset, offset, worldWidth, worldHeight}, 5, WHITE);
}
