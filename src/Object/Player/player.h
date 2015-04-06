
#pragma once
#include "../../common.h"
#include <memory>


class cPlayerMove;

class cPlayer {
public:

  cPlayer();

  void componentInit();

  void update();
  void draw();


private:

  Texture m_image;
  void drawPlayer();

  std::shared_ptr<cPlayerMove> m_move;
};