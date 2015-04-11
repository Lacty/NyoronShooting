
#pragma once
#include "../../common.h"
#include <memory>


class cEnemy {
public:

  cEnemy();

  void update(float2*);
  void draw();


private:
  
  void popUpCount();
  void enemyMove();
  void collisionShotToEnemy(float2*);

  bool collisionPointToRect(float2& point,
    float2& pos, float2& size)
  {
    if ((point.x > pos.x) &&
      (point.x < pos.x + size.x)) {
      if ((point.y > pos.y) &&
        (point.y < pos.y + size.y))
      {
        return true;
      }
    }
    return false;
  }

  WindowEdge edge;

  enum EnemyNum {
    First_Num  = 3,
    Second_Num = 5
  };

  enum TriggerStatus {
    Inactive,
    Active
  }first_status, second_status;

  struct EnemyStatus {
    bool   active;
    float2 pos;
    float2 size;
  };

  EnemyStatus first_enemy[First_Num];
  EnemyStatus second_enemy[Second_Num];

  Texture image;
};