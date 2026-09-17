#include "board.h"
#include "game.h"

int main(void) {
  int grid[8][8];
  init(grid);
  game_loop(grid);
  return 0;
}
