#include <stdio.h>
#include "game.h"
#include "board.h"
#include "input.h"
#include "rules.h"
#include "move.h"

void game_loop(int grid[8][8]) {
  while (1) {
    print(grid);

    char sel[3], dest_str[3];

    printf("Piece to move:\n");
    selpos(sel);
    pos from = charpos(sel);

    printf("Destination:\n");
    selpos(dest_str);
    pos dest = charpos(dest_str);

    if (!in_board(from) || !in_board(dest)) {
      printf("Out of bounds. Try again.\n");
      continue;
    }

    int pce = grid[from.x][from.y];

    if (pce == EMPTY) {
      printf("Empty cell.\n");
      continue;
    }

    if (!is_legal(pce, from, dest)) {
      printf("Illegal move.\n");
      continue;
    }

    move(grid, from, dest);
  }
}
