#ifndef TYPES_H
#define TYPES_H

typedef struct {
    int x;
    int y;
} pos;

typedef enum {
    EMPTY = 0,
    PAWN,
    BISHOP,
    KNIGHT,
    ROOK,
    QUEEN,
    KING
} PieceType;

#endif
