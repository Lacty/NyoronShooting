
#include "player.h"
#include "player_move.h"


cPlayer::cPlayer() :
m_image("res/texture/nyoron.png")
{
  componentInit();
}


void cPlayer::componentInit() {
  if (m_move == nullptr)
    m_move = std::make_shared<cPlayerMove>(this);
}

void cPlayer::update() {
  m_move->update();
}

void cPlayer::draw() {
  drawPlayer();
}

void cPlayer::drawPlayer() {
  static float2 pos  = float2::Zero();
  pos  = m_move->getPos();
  static float2 size = float2::Zero();
  size = float2(42, 60);
  drawTextureBox(pos.x, pos.y, size.x, size.y,
                 0, 0, 200, 300,
                 m_image,
                 Color(1, 1, 1));
}