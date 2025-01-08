#include "maze.h"
#include <stdio.h>
#include <stdlib.h>

// 生成迷宮
void generateMaze(int maze[HEIGHT][WIDTH]) {
    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
            maze[i][j] = 0;
        }
    }
    for (int row = 0; row < WIDTH; row++){
        maze[row][0] = 2;
        maze[row][HEIGHT - 1] = 2;
    }
    for (int col = 1; col < HEIGHT - 1; col++){
        maze[0][col] = 2;
        maze[WIDTH - 1][col] = 2;
    }
}

// 打印迷宮
void printMaze(int maze[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 0) printf("%c", ' ');
            if (maze[i][j] == 1) printf("%c", '0');
            if (maze[i][j] == 2) printf("%c", '#');
        }
        printf("\n");
    }
}
