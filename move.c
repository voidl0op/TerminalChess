#include "types.h"
#include "input.h"

int move(int grid[8][8], pos from, pos dest) {
  grid[dest.x][dest.y] = grid[from.x][from.y];
  if(from.x != dest.x && from.y != dest.y) grid[from.x][from.y] = 0;

}

