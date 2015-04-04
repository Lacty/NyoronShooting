
#pragma once
#include "../System/env.h"


class cSceneManager;

class cScene {
protected:

  cScene(cSceneManager*);

  cSceneManager* m_manager;


public:

  virtual void update() = 0;
  virtual void draw()   = 0;
};