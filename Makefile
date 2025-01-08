CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/maze.c src/player.c
OUT = build/maze_game

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
