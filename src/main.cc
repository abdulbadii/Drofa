#include "uci.h"
#include "attacks.h"
#include "movepicker.h"
#include "eval.h"
#include "rays.h"

extern HASH myHASH;

int main() {
  Rays::init();
  PSquareTable::init();
  ZKey::init();
  Attacks::init();
  Eval::init();
  Uci::init();

  Uci::start();

  return 0;
}