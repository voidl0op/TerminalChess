CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = main.c board.c input.c rules.c move.c game.c
BIN = chess

$(BIN): $(SRC)
	$(CC) $(CFLAGS) -o $(BIN) $(SRC)

clean:
	rm -f $(BIN)

.PHONY: clean
