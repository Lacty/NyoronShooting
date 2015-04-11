
#include "main_game.h"
#include "../System/scene_manager.h"


cMainGame::cMainGame(cSceneManager* manager) :
cScene(manager) {}


void cMainGame::update() {
  m_player.update();
  m_enemy.update();
}

void cMainGame::draw() {
  m_bg.draw();
  m_player.draw();
  m_enemy.draw();
}