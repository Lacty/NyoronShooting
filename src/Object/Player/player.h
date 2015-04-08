
#pragma once
#include "../../common.h"
#include <memory>


class cPlayerMove;
class cPlayerShot;

class cPlayer {
public:

  cPlayer();

  void componentInit();

  void update();
  void draw();

  float2 getPos() const;


private:

  Texture m_image;
  void drawPlayer();

  std::shared_ptr<cPlayerMove> m_move;
  std::shared_ptr<cPlayerShot> m_shot;
};