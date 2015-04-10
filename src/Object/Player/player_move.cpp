
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
  moveBound();
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

void cPlayerMove::moveBound() {
  if ((m_pos.x < m_edge.left) ||
      (m_pos.x + m_player->getSize().x > m_edge.right))
  {
    m_pos.x = std::max(m_pos.x, m_edge.left);
    m_pos.x = std::min(m_pos.x, m_edge.right - m_player->getSize().x);
  }
  if ((m_pos.y < m_edge.bottom) ||
      (m_pos.y + m_player->getSize().y > m_edge.top))
  {
    m_pos.y = std::max(m_pos.y, m_edge.bottom);
    m_pos.y = std::min(m_pos.y, m_edge.top - m_player->getSize().y);
  }
}

float2 cPlayerMove::getPos() {
  return m_pos;
}