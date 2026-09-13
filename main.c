/* TODO: ehhhhhh add a typedef position and a function that gets the
 * slected piece and a function the place to move it to and if both
 * are valid ( another fct ) pass them to move
 * and maybe add colors after
 * */

/* 0 = empty 
 * 1 = pawn
 * 2 = bishop 
 * 3 = knight
 * 4 = rook 
 * 5 = queen
 * 6 = king
 */

#include <stdio.h>

//inisialasies a chess board
void init(int grid[8][8]);
void print(int grid[8][8]);
//uses the number then letter to compute the move
void move(int grid[8][8]);
//checks for legal moves
void legal(int grid[8][8]);

int main () {
  int grid[8][8];
  init(grid);
  print(grid);
  move(grid);
  return 0;
}

void init(int grid[8][8]) {
    int i, j;

    for (i = 0; i < 8; i++) {
        if (i == 1 || i == 6) {
            for (j = 0; j < 8; j++) {
                grid[i][j] = 1;
            }
        }
        else if (i == 0 || i == 7) {
            if (i == 0) {
                grid[i][0] = 4;
                grid[i][1] = 3;
                grid[i][2] = 2;
                grid[i][3] = 5;
                grid[i][4] = 6;
                grid[i][5] = 2;
                grid[i][6] = 3;
                grid[i][7] = 4;
            }
            else {
                grid[i][0] = 4;
                grid[i][1] = 3;
                grid[i][2] = 2;
                grid[i][3] = 6;
                grid[i][4] = 5;
                grid[i][5] = 2;
                grid[i][6] = 3;
                grid[i][7] = 4;
            }
        }
        else {
            for (j = 0; j < 8; j++) {
                grid[i][j] = 0;
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
      printf(" %s |", symbols[grid[i][j]]); // uses the value stored in grid as the ID of the symbol really smart
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

void move(int grid[8][8]) {
  char numbers[57];
  numbers[49] = 0;  // '1'
  numbers[50] = 1;  // '2'
  numbers[51] = 2;  // '3'
  numbers[52] = 3;  // '4'
  numbers[53] = 4;  // '5'
  numbers[54] = 5;  // '6'
  numbers[55] = 6;  // '7'
  numbers[56] = 7;  // '8'
  char chars[105];
  chars[97] = 0;  // 'a'
  chars[98] = 1;  // 'b'
  chars[99] = 2;  // 'c'
  chars[100] = 3; // 'd'
  chars[101] = 4; // 'e'
  chars[102] = 5; // 'f'
  chars[103] = 6; // 'g'
  chars[104] = 7; // 'h'
  char piece[3];    // the piece that will be moved
  char themove[3];  // where it will be moved to
  int piece1; // row
  int piece2; // column
  int move1;  // row
  int move2;  // column

  printf("Enter the piece to move (1a format): ");
  scanf("%s", piece);
  printf("Enter the move (1a format): ");
  scanf("%s", themove);

  piece1 = numbers[piece[0]];
  piece2 = chars[piece[1]];
  move1  = numbers[themove[0]];
  move2  = chars[themove[1]];

  grid[move1][move2] = grid[piece1][piece2];
  grid[piece1][piece2] = 0;
  print(grid);
}

void legal(int grid[8][8], int type) {


}
