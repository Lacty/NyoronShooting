
#pragma once
#include "../../common.h"
#include "player_interface.h"


class cPlayerShot : public cPlayerInterface {
public:

  cPlayerShot(cPlayer*);

  void update();
  void draw();


private:

  void createShot();
  void shotsMove();
  void shotsBound();

  WindowEdge edge;

  enum {
    Shot_Max   = 4,
    Shot_Speed = 20
  };
  enum ShotStatus {
    Inactive,
    Active
  };

  struct ShotData {
    ShotStatus status;
    float2     pos;
  } shots[Shot_Max];
};