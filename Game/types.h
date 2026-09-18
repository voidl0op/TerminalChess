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

typedef enum {
    WHITE = 0,
    BLACK = 1
} Color;

typedef struct {
    PieceType type;
    Color color;
} Piece;

typedef enum {
    TOP = 0,
    BOTTOM = 7,
    RIGHT = 0,
    LEFT = 7
} borders;

#endif
