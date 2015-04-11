
#include "enemy.h"
#include <iostream>


enum TextureSize {
  Size_W = 75,
  Size_H = 50,
  Cut_W  = 75,
  Cut_H  = 50
};

enum MoveSpeed {
  Speed_X = 4,
  Speed_Y = 4
};

cEnemy::cEnemy() :
first_status(Inactive),
second_status(Inactive),
image("res/texture/enemy.png")
{
  for (int i = 0; i < First_Num; ++i) {
    first_enemy[i].active = true;
    first_enemy[i].pos    = float2(edge.right + (i * Size_W), edge.top + (i * Size_H));
    first_enemy[i].size   = float2(Size_W, Size_H);
  }
  for (int i = 0; i < Second_Num; ++i) {
    second_enemy[i].active = true;
    second_enemy[i].pos    = float2(edge.left - Size_W - (i * Size_W), edge.top + i * Size_H);
    second_enemy[i].size   = float2(Size_W, Size_H);
  }
}


void cEnemy::update(float2* shot_pos) {
  popUpCount();
  enemyMove();
  collisionShotToEnemy(shot_pos);
}

void cEnemy::draw() {
  for (int i = 0; i < First_Num; ++i) {
    if (first_enemy[i].active) {
      drawTextureBox(first_enemy[i].pos.x,
                     first_enemy[i].pos.y,
                     Size_W, Size_H,
                     0, 0, Cut_W, Cut_H,
                     image,
                     Color::white);
    }
  }
  for (int i = 0; i < Second_Num; ++i) {
    if (second_enemy[i].active) {
      drawTextureBox(second_enemy[i].pos.x,
                     second_enemy[i].pos.y,
                     Size_W, Size_W,
                     0, 0, Cut_W, Cut_H,
                     image,
                     Color::white);
    }
  }
}


void cEnemy::enemyMove() {
  if (first_status == Active) {
    for (int i = 0; i < First_Num; ++i) {
      first_enemy[i].pos.x -= Speed_X;
      first_enemy[i].pos.y -= Speed_Y;
    }
  }
  if (second_status == Active) {
    for (int i = 0; i < Second_Num; ++i) {
      second_enemy[i].pos.x += Speed_X;
      second_enemy[i].pos.y -= Speed_Y;
    }
  }
}


void cEnemy::popUpCount() {
  static float count = 0;
  count += (1.0f / 60.0f);

  const float first_enemy_trigger = 2.0f;
  const float second_enemy_trigger = 5.0f;

  if (count >= first_enemy_trigger) {
    first_status = Active;
  }
  if (count >= second_enemy_trigger) {
    second_status = Active;
  }
}

void cEnemy::collisionShotToEnemy(float2* shot_pos) {
  for (int e = 0; e < First_Num; ++e) {
    if (first_enemy[e].active){
      for (int s = 0; s < 4; ++s) {
        if (collisionPointToRect(shot_pos[s], first_enemy[e].pos,
                                 first_enemy[e].size))
        {
          first_enemy[e].active = false;
        }
      }
    }
  }
  for (int e = 0; e < Second_Num; ++e) {
    if (second_enemy[e].active){
      for (int s = 0; s < 4; ++s) {
        if (collisionPointToRect(shot_pos[s], second_enemy[e].pos,
                                 second_enemy[e].size))
        {
          second_enemy[e].active = false;
        }
      }
    }
  }
}

bool cEnemy::getStatusOfLastEnemy() const {
  return second_enemy[Second_Num].active;
}

float2 cEnemy::getPosOfLastEnemy() const {
  return second_enemy[Second_Num].pos;
}