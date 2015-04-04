
#include "scene_manager.h"
#include "../Scene/title.h"


void mng::init() {
  m_current_scene = std::make_shared<cTitle>(this);
}


void mng::update() {
  m_current_scene->update();
}

void mng::draw() {
  cEnv::get()->begin();

  m_current_scene->draw();

  cEnv::get()->end();
}


void mng::shiftNextScene(std::shared_ptr<cScene> next_scene) {
  m_current_scene = next_scene;
}