
#pragma once
#include "scene.h"
#include "../common.h"
#include "../Object/BackGround/back_ground.h"
#include "../Object/Player/player.h"
#include "../Object/Enemy/enemy.h"
#include "../Object/Smoche/smoche.h"


class cMainGame : public cScene {
public:

  cMainGame(cSceneManager*);

  void update();
  void draw();


private:

  cBackGround m_bg;
  cPlayer     m_player;
  cEnemy      m_enemy;
  cSmoche     m_smoche;
};