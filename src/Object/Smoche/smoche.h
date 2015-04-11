
#pragma once
#include "../../common.h"


class cSmoche {
public:

  cSmoche();

  void update(bool, float2);
  void draw();


private:

  void initPos(float2&);
  bool is_init;

  Texture image;
  float2  m_pos;
  bool    active;
};