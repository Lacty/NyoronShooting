
#pragma once
#include "../../common.h"


class cBackGround {
public:

  cBackGround();

  void update();
  void draw();


private:

  enum TextureStatus {
    Size_W = 512,
    Size_H = 1024,

    Cut_Size_W = 256,
    Cut_Size_H = 512
  };

  Texture m_image;

  float2 m_pos;
  float2 m_size;

  const float anime_speed = -0.4f;
};

typedef cBackGround bg;