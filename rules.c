#include <stdbool.h>
#include <stdlib.h>
#include "types.h"
#include "rules.h"
#include "board.h"

bool in_board(pos dest) {
    return dest.x >= RIGHT && dest.x <= LEFT && dest.y >= TOP && dest.y <= BOTTOM;
}

bool is_clear(Piece grid[8][8], pos from, pos dest) {
    int dx = dest.x - from.x;
    int dy = dest.y - from.y;
    int stepx = (dx > 0) - (dx < 0);
    int stepy = (dy > 0) - (dy < 0);

    int x = from.x + stepx;
    int y = from.y + stepy;
    while (x != dest.x || y != dest.y) {
        if (grid[x][y].type != EMPTY) return false;
        x += stepx;
        y += stepy;
    }
    return true;
}

static bool pawn_legal(Piece grid[8][8], pos from, pos dest, Color color) {
    int dx = dest.x - from.x;
    int dy = dest.y - from.y;
    int dir = (color == WHITE) ? 1 : -1;
    int start_row = (color == WHITE) ? 1 : 6;
    Piece target = grid[dest.x][dest.y];

    if (dy == 0) {
        // straight push, never a capture
        if (target.type != EMPTY) return false;
        if (dx == dir) return true;
        if (dx == 2 * dir && from.x == start_row) {
            pos mid = { from.x + dir, from.y };
            return grid[mid.x][mid.y].type == EMPTY;
        }
        return false;
    }

    if (abs(dy) == 1 && dx == dir) {
        // diagonal capture only (en passant not yet implemented)
        return target.type != EMPTY && target.color != color;
    }

    return false;
}

bool is_legal(Piece grid[8][8], pos from, pos dest) {
    if (!in_board(from) || !in_board(dest)) return false;
    if (from.x == dest.x && from.y == dest.y) return false;

    Piece p = grid[from.x][from.y];
    if (p.type == EMPTY) return false;

    Piece target = grid[dest.x][dest.y];
    if (target.type != EMPTY && target.color == p.color) return false; // no friendly fire

    int dx = dest.x - from.x;
    int dy = dest.y - from.y;

    switch (p.type) {
        case PAWN:
            return pawn_legal(grid, from, dest, p.color);
        case KNIGHT:
            return (abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2);
        case BISHOP:
            if (abs(dx) != abs(dy)) return false;
            return is_clear(grid, from, dest);
        case ROOK:
            if (dx != 0 && dy != 0) return false;
            return is_clear(grid, from, dest);
        case QUEEN:
            if (dx != 0 && dy != 0 && abs(dx) != abs(dy)) return false;
            return is_clear(grid, from, dest);
        case KING:
            // TODO: castling
            return abs(dx) <= 1 && abs(dy) <= 1;
        default:
            return false;
    }
}

bool is_in_check(Piece grid[8][8], Color color) {
    pos king;
    if (!find_king(grid, color, &king)) return false; // no king on board (shouldn't happen)

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece p = grid[i][j];
            if (p.type == EMPTY || p.color == color) continue;
            pos from = { i, j };
            if (is_legal(grid, from, king)) return true;
        }
    }
    return false;
}

bool leaves_king_in_check(Piece grid[8][8], pos from, pos dest, Color color) {
    Piece saved_from = grid[from.x][from.y];
    Piece saved_dest = grid[dest.x][dest.y];

    grid[dest.x][dest.y] = saved_from;
    grid[from.x][from.y] = (Piece){ EMPTY, WHITE };

    bool check = is_in_check(grid, color);

    grid[from.x][from.y] = saved_from;
    grid[dest.x][dest.y] = saved_dest;

    return check;
}

bool has_any_legal_move(Piece grid[8][8], Color color) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece p = grid[i][j];
            if (p.type == EMPTY || p.color != color) continue;
            pos from = { i, j };
            for (int di = 0; di < 8; di++) {
                for (int dj = 0; dj < 8; dj++) {
                    pos dest = { di, dj };
                    if (is_legal(grid, from, dest) && !leaves_king_in_check(grid, from, dest, color)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
