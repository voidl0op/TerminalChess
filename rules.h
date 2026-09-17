#ifndef RULES_H
#define RULES_H
#include <stdbool.h>

bool in_board(pos dest);
bool is_clear(int pce, pos from, pos dest);
bool is_legal(int pce, pos from, pos dest);

#endif
