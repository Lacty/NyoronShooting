
#pragma once
#include "../../common.h"
#include "player_interface.h"


class cPlayerMove : public cPlayerInterface {
public:

  cPlayerMove(cPlayer*);

  void   update();
  float2 getPos();


private:

  float2 m_pos;
  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();

  enum Button {
    UP    = 'W',
    DOWN  = 'S',
    LEFT  = 'A',
    RIGHT = 'D'
  };

  enum MoveSpeed {
    SPEED_X = 6,
    SPEED_Y = 6
  };

  enum InitPos {
    POS_X = -20,
    POS_Y = -220
  };
};