
#include "player.h"
#include "player_move.h"
#include "player_shot.h"


cPlayer::cPlayer() :
m_image("res/texture/nyoron.png"),
m_size(float2(42, 60))
{
  componentInit();
}


void cPlayer::componentInit() {
  if (m_move == nullptr)
    m_move = std::make_shared<cPlayerMove>(this);

  if (m_shot == nullptr)
    m_shot = std::make_shared<cPlayerShot>(this);
}

void cPlayer::update() {
  m_move->update();
  m_shot->update();
}

void cPlayer::draw() {
  drawPlayer();
  m_shot->draw();
}

void cPlayer::drawPlayer() {
  m_pos = m_move->getPos();
  drawTextureBox(m_pos.x, m_pos.y, m_size.x, m_size.y,
                 0, 0, 200, 300,
                 m_image,
                 Color(1, 1, 1));
}

float2 cPlayer::getPos() const {
  return m_move->getPos();
}

float2 cPlayer::getSize() const {
  return m_size;
}

float2* cPlayer::getShotPos() const {
  return m_shot->getShotPos();
}