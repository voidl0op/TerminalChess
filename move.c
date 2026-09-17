#include <stdio.h>
#include "types.h"
#include "move.h"

static PieceType ask_promotion(void) {
    char c;
    while (1) {
        printf("Promote to (Q/R/B/N): ");
        if (scanf(" %c", &c) != 1) return QUEEN; // EOF: default to queen
        switch (c) {
            case 'q': case 'Q': return QUEEN;
            case 'r': case 'R': return ROOK;
            case 'b': case 'B': return BISHOP;
            case 'n': case 'N': return KNIGHT;
            default: printf("Not a valid choice.\n");
        }
    }
}

void move(Piece grid[8][8], pos from, pos dest) {
    Piece p = grid[from.x][from.y];

    if (p.type == PAWN && (dest.x == 0 || dest.x == 7)) {
        p.type = ask_promotion();
    }

    grid[dest.x][dest.y] = p;
    grid[from.x][from.y] = (Piece){ EMPTY, WHITE };
}
