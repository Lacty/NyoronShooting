
#include "System/env.h"
#include "System/game_player.h"


int main() {
  cEnv::get();
  cGamePlayer game;
  game.run();
}
