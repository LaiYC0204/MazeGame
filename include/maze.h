#ifndef MAZE_H
#define MAZE_H

// 定義常數
#define WIDTH 11
#define HEIGHT 9
#define MAX_QUEUE_SIZE (WIDTH - 1)*(HEIGHT - 1)

typedef struct {
    int x;
    int y;
} Node;

// 函數原型
void generateMaze();
Node searchMinDistance(Node queue[MAX_QUEUE_SIZE], int front);
void breakWall(Node minDistance);
void printMaze(int playerX, int playerY);
int* getMaze();

#endif