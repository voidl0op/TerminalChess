# TerminalChess

A chess game that runs entirely in the terminal, written in C.

```
    a   b   c   d   e   f   g   h
  ---------------------------------
8 | ♜ | ♞ | ♝ | ♛ | ♚ | ♝ | ♞ | ♜ |
  ---------------------------------
7 | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ |
  ---------------------------------
6 |   |   |   |   |   |   |   |   |
  ---------------------------------
5 |   |   |   |   |   |   |   |   |
  ---------------------------------
4 |   |   |   |   |   |   |   |   |
  ---------------------------------
3 |   |   |   |   |   |   |   |   |
  ---------------------------------
2 | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ |
  ---------------------------------
1 | ♖ | ♘ | ♗ | ♕ | ♔ | ♗ | ♘ | ♖ |
  ---------------------------------
```

## Building

```bash
make
```

This produces a `chess` binary in the project root.

```bash
make clean
```

Removes the compiled binary.

## Running

```bash
./chess
```

Moves are entered as two squares in algebraic notation (file letter + rank number), e.g.:

```
Move from (e.g. e2): e2
Move to (e.g. e2): e4
```

## Project structure

The codebase is split by responsibility rather than kept as one file:

| File | Responsibility |
|---|---|
| `types.h` | Shared typedefs — `pos`, `PieceType` enum, etc. |
| `board.c` / `board.h` | Board representation, initial setup, printing the grid |
| `input.c` / `input.h` | Reading and parsing user input into board positions |
| `rules.c` / `rules.h` | Move legality — is a given move valid for a given piece |
| `move.c` / `move.h` | Applying a legal move to the board |
| `game.c` / `game.h` | Main game loop — tying input, rules, and move together, turn tracking |
| `main.c` | Entry point |

Each module is meant to be usable and testable on its own — `rules.c`, for example, has no `printf`/`scanf` in it at all, so move legality can eventually be unit-tested independently of the game loop.

## Status

This project is a work in progress and under active restructuring. Current state:

- [x] Board setup and printing
- [x] Input parsing (square notation → internal position)
- [ ] Move legality per piece type (in progress)
- [ ] Applying moves / turn switching
- [ ] Check / checkmate / stalemate detection
- [ ] Castling
- [ ] En passant
- [ ] Pawn promotion

## License

Not yet decided.
