
#include "title.h"
#include "../System/scene_manager.h"
#include "../System/env.h"
#include "main_game.h"
#include <memory>


cTitle::cTitle(cSceneManager* manager) :
cScene(manager),
font("res/font/chogokubosogothic_5.ttf"),
font_alpha(1)
{
  font.size(static_cast<u_int>(Font::Size));
}


void cTitle::update() {
  fontAlpha();
  gotoNextScene();
}

void cTitle::draw() {
  static float2 pos   = float2(-150, 0);
  static float  count = 0.3f;
  font.draw("Push Any Key", pos, count, Color(0.0f, 0.2f, 1.0f, font_alpha));
}

void cTitle::fontAlpha() {
  const  float time = 0.06f;
  static float anime = 0.0f;
  const  float angle = 1.2f;
  anime += time;
  font_alpha = sin(anime) + angle;
}

void cTitle::gotoNextScene() {
  if (!cEnv::get()->isPushButton(Mouse::LEFT)) return;
  m_manager->shiftNextScene(std::make_shared<cMainGame>(m_manager));
}