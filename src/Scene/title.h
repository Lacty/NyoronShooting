
#pragma once
#include "scene.h"
#include "../common.h"


class cTitle : public cScene {
public:

  cTitle(cSceneManager*);

  void update();
  void draw();


private:

  enum class Font : u_int {
    Size = 50
  };
  float    font_alpha;
  void     fontAlpha();
  cAldFont font;

  void     gotoNextScene();
};