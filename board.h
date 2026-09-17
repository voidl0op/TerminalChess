#ifndef BOARD_H
#define BOARD_H
#include <stdbool.h>
#include "types.h"

void init(Piece grid[8][8]);
void print(Piece grid[8][8]);
bool find_king(Piece grid[8][8], Color color, pos *out);

#endif
