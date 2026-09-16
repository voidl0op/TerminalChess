CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = src/main.c src/board.c src/input.c src/rules.c src/move.c src/game.c
BIN = chess

$(BIN): $(SRC)
	$(CC) $(CFLAGS) -o $(BIN) $(SRC)

clean:
	rm -f $(BIN)

.PHONY: clean
