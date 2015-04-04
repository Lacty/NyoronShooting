
#pragma once
#include "env.h"
#include "scene_manager.h"
#include <memory>


class cGamePlayer {
public:

  cGamePlayer() = default;

  void run() {
    m_manager.init();

    while (cEnv::get()->isOpen()){
      m_manager.update();
      m_manager.draw();
    }
  }


private:

  cSceneManager m_manager;
};