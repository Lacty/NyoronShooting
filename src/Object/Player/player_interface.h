
#pragma once
#include "../../common.h"


class cPlayer;

class cPlayerInterface {
protected:

  cPlayer* m_player;
  
  cPlayerInterface(cPlayer*);


  virtual void update() = 0;
};