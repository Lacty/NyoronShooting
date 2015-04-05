
#pragma once
#include "env.h"


class cScene;

class cSceneManager {
public:

  cSceneManager() = default;

  void init();

  void update();
  void draw();

  void shiftNextScene(std::shared_ptr<cScene> next_scene);


private:

  std::shared_ptr<cScene> m_current_scene;
};

typedef cSceneManager mng;