
#pragma once
#include "../../common.h"
#include <memory>


class cEnemy {
public:

  cEnemy();

  void update();
  void draw();


private:
  
  void popUpCount();
  void enemyMove();

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
};