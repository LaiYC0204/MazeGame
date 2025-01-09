#include "maze.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 生成迷宮
void generateMaze(int maze[HEIGHT][WIDTH]) {
    // 設定亂數種子
    srand(time(NULL));

    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
            maze[i][j] = 0;
        }
    }
    for (int row = 0; row < WIDTH; row++){
        maze[row][0] = 1;
        maze[row][HEIGHT - 1] = 1;
    }
    for (int col = 1; col < HEIGHT - 1; col++){
        maze[0][col] = 1;
        maze[WIDTH - 1][col] = 1;
    }

    // 迷宮內隨機生成牆壁
    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
            maze[i][j] =  rand() % (1 - 0 + 1) + 0; // 0 or 1
        }
    }
}

// 打印迷宮
void printMaze(int maze[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 0) printf("%c", ' '); // 空地
            if (maze[i][j] == 1) printf("%c", '#'); // 牆壁
            if (maze[i][j] == 2) printf("%c", '0'); // 玩家
            if (maze[i][j] == 3) printf("%c", '*'); // 終點
        }
        printf("\n");
    }
}
