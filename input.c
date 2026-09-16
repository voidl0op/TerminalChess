#include <stdio.h>
#include "types.h"
void selpos(char sel[3]) {
  char sel[3];
  printf("Selectionez une piece\n");
  printf("(a->h) and (1->8): ");
  scanf("%s", sel);
}

pos charpos(char sel[3]) {
  pos position;
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
  position.y = chars[sel[0]];
  position.x = numbers[sel[1]];

  return position;
}
