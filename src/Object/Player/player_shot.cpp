
#include "../../System/env.h"
#include "player_shot.h"
#include "player.h"


cPlayerShot::cPlayerShot(cPlayer* player) :
cPlayerInterface(player)
{
  for (int i = 0; i < Shot_Max; ++i) {
    shots[i].status = Inactive;
    shots[i].pos    = float2::Zero();
  }
}


void cPlayerShot::update() {
  createShot();
  shotsMove();
  shotsBound();
}

void cPlayerShot::draw() {
  for (int i = 0; i < Shot_Max; ++i) {
    if (shots[i].status == Active)
    drawBox(shots[i].pos.x, shots[i].pos.y,
            10, 10, 2,
            Color::black);
  }
}


void cPlayerShot::createShot() {
  if (!cEnv::get()->isPullKey(GLFW_KEY_SPACE)) return;
  for (int i = 0; i < Shot_Max; ++i) {
    if (shots[i].status == Inactive) {
      shots[i].status = Active;
      shots[i].pos.x = m_player->getPos().x +
                      (m_player->getSize().x / 3);
      shots[i].pos.y = m_player->getPos().y +
                      (m_player->getSize().y / 2);
      break;
    }
  }
}

void cPlayerShot::shotsMove() {
  for (int i = 0; i < Shot_Max; ++i) {
    if (shots[i].status == Active) {
      shots[i].pos.y += Shot_Speed;
    }
  }
}

void cPlayerShot::shotsBound() {
  for (int i = 0; i < Shot_Max; ++i) {
    if (shots[i].pos.y > edge.top)
      shots[i].status = Inactive;
  }
}