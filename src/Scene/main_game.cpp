
#include "main_game.h"
#include "../System/scene_manager.h"


cMainGame::cMainGame(cSceneManager* manager) :
cScene(manager) {}


void cMainGame::update() {
  m_bg.update();
  m_player.update();
}

void cMainGame::draw() {
  m_bg.draw();
  m_player.draw();
}