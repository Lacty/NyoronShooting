
#pragma once
#include "scene.h"
#include "../common.h"
#include "../Object/Player/player.h"


class cMainGame : public cScene {
public:

  cMainGame(cSceneManager*);

  void update();
  void draw();


private:

  cPlayer m_player;
};