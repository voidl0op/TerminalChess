#include "types.h"
#include <stdio.h>

void init(int grid[8][8]) {
    int i, j;

    for (i = 0; i < 8; i++) {
        if (i == 1 || i == 6) {
            for (j = 0; j < 8; j++) {
                grid[i][j] = PAWN;
            }
        }
        else if (i == 0 || i == 7) {
            if (i == 0) {
                grid[i][0] = ROOK;
                grid[i][1] = KNIGHT;
                grid[i][2] = BISHOP;
                grid[i][3] = QUEEN;
                grid[i][4] = KING;
                grid[i][5] = BISHOP;
                grid[i][6] = KNIGHT;
                grid[i][7] = ROOK;
            }
            else {
                grid[i][0] = ROOK;
                grid[i][1] = KNIGHT;
                grid[i][2] = BISHOP;
                grid[i][3] = KING;
                grid[i][4] = QUEEN;
                grid[i][5] = BISHOP;
                grid[i][6] = KNIGHT;
                grid[i][7] = ROOK;
            }
        }
        else {
            for (j = 0; j < 8; j++) {
                grid[i][j] = EMPTY;
            }
        }
    }
}

void print(int grid[8][8]) {
  const char* letter[] = {"a","b","c","d","e","f","g","h"};
  const char* symbols[] = { " ", "♙", "♗", "♘", "♖", "♕", "♔" };
  printf("    ");
  for( int j = 0; j<8; j++) {
      printf("%s   ", letter[j]);
  }
  printf("\n");
  printf("  ");
  for( int j = 0; j<8; j++) {
      printf("----");
  }
  printf("-");
  printf("\n");
  for( int i = 0; i<8; i++) {
    printf("%d |", i+1);
    for( int j = 0; j<8; j++) {
      printf(" %s |", symbols[grid[i][j]]);
    }
    printf("\n");
    printf("  ");
    for( int j = 0; j<8; j++) {
      printf("----");
    }
    printf("-");
    printf("\n");
  }
}
