#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "player.h"

int main() {
    int maze[HEIGHT][WIDTH];
    Player player = {1, 1};
    generateMaze(maze);
    maze[player.y][player.x] = 1; // 保證起點是空地

    char input;
    while (1) {
        system("cls");
        printMaze(maze);
        printf("\nMove (w/a/s/d): ");
        scanf(" %c", &input);
        movePlayer(maze, &player, input);
    }

    return 0;
}
