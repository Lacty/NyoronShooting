
#include "smoche.h"


enum TextureSize {
  Size_W = 100,
  Size_H = 175,
  Cut_Pos_Y = 100
};

cSmoche::cSmoche() :
image("res/texture/enemy.png"),
is_init(false),
active(false) {}


void cSmoche::update(bool is_active_last_enemy,
                     float2 last_enemy_pos) {
  if (is_active_last_enemy) return;
  
  if (!is_init)
  {
    initPos(last_enemy_pos);
  }

  active = true;
  const  float g  = -0.04f;
  static float vy = 0.0f;

  vy += g;
  m_pos.y += vy;
}

void cSmoche::draw() {
  drawTextureBox(m_pos.x, m_pos.y, Size_W, Size_H,
                 0, Cut_Pos_Y, Size_W, Size_H,
                 image,
                 Color::white);
}


void cSmoche::initPos(float2& last_enemy_pos) {
  m_pos = last_enemy_pos;
  is_init = true;
}