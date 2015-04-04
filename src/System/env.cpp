
#include "env.h"


AppEnv* cEnv::get() {
  static AppEnv s_env(WIDTH, HEIGHT);
  return &s_env;
}