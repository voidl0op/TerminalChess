#include <stdio.h>
#include "game.h"
#include "board.h"
#include "input.h"
#include "rules.h"
#include "move.h"

static const char* color_name(Color c) {
    return c == WHITE ? "White" : "Black";
}

// reads one square from the player, re-prompting until it's valid input
// (as opposed to a *legal move* -- that's checked separately)
static bool read_square(pos *out) {
    char sel[8];
    if (!selpos(sel)) return false; // EOF / read failure
    if (!charpos(sel, out)) {
        printf("Not a square (use a letter a-h then a digit 1-8, e.g. e2).\n");
        return read_square(out);
    }
    return true;
}

void game_loop(Piece grid[8][8]) {
    Color turn = WHITE;

    while (1) {
        print(grid);

        if (!has_any_legal_move(grid, turn)) {
            if (is_in_check(grid, turn)) {
                printf("Checkmate! %s wins.\n", color_name(turn == WHITE ? BLACK : WHITE));
            } else {
                printf("Stalemate. It's a draw.\n");
            }
            return;
        }

        if (is_in_check(grid, turn)) {
            printf("%s is in check.\n", color_name(turn));
        }

        printf("%s to move.\n", color_name(turn));

        pos from, dest;

        printf("Piece to move:\n");
        if (!read_square(&from)) return; // EOF

        printf("Destination:\n");
        if (!read_square(&dest)) return; // EOF

        Piece p = grid[from.x][from.y];

        if (p.type == EMPTY) {
            printf("That square is empty.\n");
            continue;
        }

        if (p.color != turn) {
            printf("That's not your piece.\n");
            continue;
        }

        if (!is_legal(grid, from, dest)) {
            printf("Illegal move.\n");
            continue;
        }

        if (leaves_king_in_check(grid, from, dest, turn)) {
            printf("That move would leave your king in check.\n");
            continue;
        }

        move(grid, from, dest);
        turn = (turn == WHITE) ? BLACK : WHITE;
    }
}
