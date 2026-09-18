#include "types.h"
#include "board.h"
#include <stdio.h>

void init(Piece grid[8][8]) {
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            grid[i][j] = (Piece){ EMPTY, WHITE };
        }
    }

    // white pawns (rank 2) / black pawns (rank 7)
    for (j = 0; j < 8; j++) {
        grid[1][j] = (Piece){ PAWN, WHITE };
        grid[6][j] = (Piece){ PAWN, BLACK };
    }

    // back ranks: file order is the same for both colors
    // (a) rook, (b) knight, (c) bishop, (d) queen, (e) king, (f) bishop, (g) knight, (h) rook
    PieceType back_rank[8] = { ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK };

    for (j = 0; j < 8; j++) {
        grid[0][j] = (Piece){ back_rank[j], WHITE };
        grid[7][j] = (Piece){ back_rank[j], BLACK };
    }
}

bool find_king(Piece grid[8][8], Color color, pos *out) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grid[i][j].type == KING && grid[i][j].color == color) {
                out->x = i;
                out->y = j;
                return true;
            }
        }
    }
    return false;
}

// ANSI colors so the two sides are visibly distinct even when the glyphs
// render similarly in a given terminal font
#define COLOR_WHITE "\033[1;97m" // bright white
#define COLOR_BLACK "\033[1;31m" // red
#define COLOR_RESET "\033[0m"

void print(Piece grid[8][8]) {
    // both sides use the same glyph set now that color does the distinguishing
    const char* symbols[] = { " ", "♙", "♗", "♘", "♖", "♕", "♔" };
    const char* letter[] = { "a", "b", "c", "d", "e", "f", "g", "h" };

    printf("    ");
    for (int j = 0; j < 8; j++) {
        printf("%s   ", letter[j]);
    }
    printf("\n  ");
    for (int j = 0; j < 8; j++) {
        printf("----");
    }
    printf("-\n");

    // print rank 8 at the top, rank 1 at the bottom, like a real board
    for (int i = 7; i >= 0; i--) {
        printf("%d |", i + 1);
        for (int j = 0; j < 8; j++) {
            Piece p = grid[i][j];
            if (p.type == EMPTY) {
                printf("   |");
            } else {
                const char* color = (p.color == WHITE) ? COLOR_WHITE : COLOR_BLACK;
                printf(" %s%s%s |", color, symbols[p.type], COLOR_RESET);
            }
        }
        printf("\n  ");
        for (int j = 0; j < 8; j++) {
            printf("----");
        }
        printf("-\n");
    }
}
