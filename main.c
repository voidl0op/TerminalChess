#include "types.h"
#include "board.h"
#include "game.h"

int main(void) {
    Piece grid[8][8];
    init(grid);
    game_loop(grid);
    return 0;
}
