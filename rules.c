#include <stdbool.h>
#include <math.h>
#include "types.h"

bool in_board(pos dest) {
  if(dest.x >= RIGHT && dest.x <=LEFT && dest.y >=TOP && dest.y <=BOTTOM )
    return true;
  return false;
}

bool is_clear(int pce,pos from, pos dest) {

}

bool is_legal(int pce,pos from, pos dest) {
  int dx = dest.x - from.x;
  int dy = dest.y - from.y;
  switch (pce){
    case EMPTY:
      return false;
    case PAWN:
      if(abs(dx) <=2) return true;
      else return false;
    case BISHOP:
      if(abs(dx)==abs(dy)) return true;
      else return false;
    case KNIGHT:
      if((abs(dx)== 3 && abs(dy)=1)||(abs(dy)==3 && abs(dx)))
      return true;
      else return false;
    case ROOK:
      if(dx == 0 && dy != 0) return true;
      else if(dx != 0 && dy == 0) return true;
      else return false;
    case QUEEN:
      if(dx == 0 && dy != 0) return true;
      else if(dx != 0 && dy == 0) return true;
      if(abs(dx)==abs(dy)) return true;
      else return false;
    case KING:
      if(dx == 0 && dy == 1) return true;
      else if(dx ==1 && dy == 0) return true;
      if(abs(dx)==abs(dy) && abs(dx) == 1) return true;
      else return false;
    default:
      return false;
  }
}
