#ifndef RULES_H
#define RULES_H
#include <stdbool.h>
#include "types.h"

bool in_board(pos dest);
bool is_clear(Piece grid[8][8], pos from, pos dest);
bool is_legal(Piece grid[8][8], pos from, pos dest);
bool is_in_check(Piece grid[8][8], Color color);
bool leaves_king_in_check(Piece grid[8][8], pos from, pos dest, Color color);
bool has_any_legal_move(Piece grid[8][8], Color color);

#endif
