
#include "main_game.h"
#include "../System/scene_manager.h"


cMainGame::cMainGame(cSceneManager* manager) :
cScene(manager) {}


void cMainGame::update() {

}

void cMainGame::draw() {
  drawArc(0, 0, 50, 50, 0, 5, 100, 2, Color(0.0f, 0.2f, 1.0f));
}