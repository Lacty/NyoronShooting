
#include "enemy.h"
#include <iostream>


enum TextureSize {
  Size_W = 75,
  Size_H = 50,
  Cut_W  = 75,
  Cut_H  = 50
};

cEnemy::cEnemy() :
first_status(Inactive),
second_status(Inactive)
{
  for (int i = 0; i < First_Num; ++i) {
    first_enemy[i].active = false;
    first_enemy[i].pos    = float2(edge.right + (i * Size_W), i * Size_H);
    first_enemy[i].size   = float2(Size_W, Size_H);
  }
  for (int i = 0; i < Second_Num; ++i) {
    second_enemy[i].active = false;
    second_enemy[i].pos    = float2(edge.left - Size_W + (i * Size_W), i * Size_H);
    second_enemy[i].size   = float2(Size_W, Size_H);
  }
}


void cEnemy::update() {
  popUpCount();
}

void cEnemy::draw() {

}


void cEnemy::enemyMove() {

}


void cEnemy::popUpCount() {
  if (second_status == Active) return;

  static float count = 0;
  count += (1.0f / 60.0f);

  const float first_enemy_trigger = 2.0f;
  const float second_enemy_trigger = 5.0f;

  if (count >= first_enemy_trigger) {
    first_status = Active;
  }
  else if (count >= second_enemy_trigger) {
    second_status = Active;
  }
}