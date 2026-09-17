#include "types.h"
#include "input.h"
#include "move.h"

void move(int grid[8][8], pos from, pos dest) {
  grid[dest.x][dest.y] = grid[from.x][from.y];
  grid[from.x][from.y] = EMPTY;
}
