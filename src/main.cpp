
#include "System/env.h"
#include "System/game_player.h"


int main() {
  cEnv::get();
  cEnv::get()->bgColor(Color::white);
  cGamePlayer game;
  game.run();
}
