#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "maze.h"
#include "player.h"

int main() {
    int maze[HEIGHT][WIDTH];
    int finish = 1;
    Player player = {1, 1};
    srand(time(NULL));
    generateMaze(maze);
    maze[player.x][player.y] = 2; // 設定玩家位置
    maze[HEIGHT - 2][WIDTH - 2] = 3; // 終點
    
    char input;
    while (finish) {
        system("cls");
        printMaze(maze);
        printf("\nMove (w/a/s/d): ");
        scanf(" %c", &input);
        movePlayer(maze, &player, input, &finish);
    }

    return 0;
}
