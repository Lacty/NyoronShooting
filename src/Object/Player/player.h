
#pragma once
#include "../../common.h"
#include <memory>


class cPlayerMove;
class cPlayerShot;

class cPlayer {
public:

  cPlayer();

  void update();
  void draw();

  float2 getPos()  const;
  float2 getSize() const;


private:

  void componentInit();

  Texture m_image;
  void drawPlayer();

  float2 m_pos;
  float2 m_size;

  std::shared_ptr<cPlayerMove> m_move;
  std::shared_ptr<cPlayerShot> m_shot;
};