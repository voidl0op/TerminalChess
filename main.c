#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main () {
  int grid[8][8];
  init(grid);
  print(grid);
  move(grid);
  return 0;
}

bool legal(int grid[8][8]) {
  char selected[3]  = selpos();
  char destination[3] = selpos();
  pos init = chartopos(selected[3]);
  pos dest = chartopos(destination[3]);
  switch (grid[init.x][init.y]) {
    case 0:
      printf("Empty cell\n");
      selected[3] = selpos();
      init = chartopos(selected[3]);
      break;
    case 1:
      if(((abs(dest.y - init.y) == 2) || (abs(dest.y - init.y) == 1)) && (init.y != 4)) {
      return 1;
      }
      return 0;
    case 2:
      if() {
        return 1;
      }
      return 0;

    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    default: 
      printf("How did you get here bruh");
  }

}
void move(int grid[8][8]) {

}
