
#include "../../System/env.h"
#include "player_move.h"
#include "player.h"


cPlayerMove::cPlayerMove(cPlayer* player) :
cPlayerInterface(player),
m_pos(float2(POS_X, POS_Y)) {}


void cPlayerMove::update() {
  moveUp();
  moveDown();
  moveLeft();
  moveRight();
}

void cPlayerMove::moveUp() {
  if (!cEnv::get()->isPressKey(Button::UP)) return;
  m_pos.y += SPEED_Y;
}

void cPlayerMove::moveDown() {
  if (!cEnv::get()->isPressKey(Button::DOWN)) return;
  m_pos.y -= SPEED_Y;
}

void cPlayerMove::moveLeft() {
  if (!cEnv::get()->isPressKey(Button::LEFT)) return;
  m_pos.x -= SPEED_X;
}

void cPlayerMove::moveRight() {
  if (!cEnv::get()->isPressKey(Button::RIGHT)) return;
  m_pos.x += SPEED_X;
}

float2 cPlayerMove::getPos() {
  return m_pos;
}