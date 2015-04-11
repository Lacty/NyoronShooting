
#include "back_ground.h"


cBackGround::cBackGround() :
m_image("res/texture/bg.png"),
m_pos(-(Size_W * 0.5f), -(Size_H * 0.25f)),
m_size(Size_W, Size_H) {}


void bg::draw() {
  static float anime = 0.0f;
  anime += anime_speed;
  drawTextureBox(m_pos.x, m_pos.y, m_size.x, m_size.y,
                 0, anime, Cut_Size_W, Cut_Size_H,
                 m_image,
                 Color::white);
}