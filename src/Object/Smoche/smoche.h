
#pragma once
#include "../../common.h"


class cSmoche {
public:

  cSmoche();

  void update();
  void draw();


private:

  Texture image;
  float2  m_pos;
  bool    active;
};