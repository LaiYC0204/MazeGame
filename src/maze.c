#include "maze.h"
#include <stdio.h>
#include <stdlib.h>

// 生成迷宮
void generateMaze(int maze[HEIGHT][WIDTH]) {
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 上、下、左、右
    int isReachable = 0; // 是否能達到終點
    int front = 0, rear = 1;
    Node queue[MAX_QUEUE_SIZE];

    // 初始化迷宮(全部牆壁)
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = 1;
        }
    }

    // BFS 迴圈(先進先出)
    queue[0] = (Node){1, 1};
    while (front < rear) {
        Node current = queue[front++];
        if (current.x == HEIGHT - 2 && current.y == WIDTH - 2) isReachable = 1;
        for (int i = 0; i < 4; i++)
        {
            int random = rand() % 4; // 隨機方向
            int newX = current.x + directions[random][0] * 2;
            int newY = current.y + directions[random][1] * 2;

            // 檢查是否越界並且是牆壁
            if (newX > 0 && newX < HEIGHT - 1 && newY > 0 && newY < WIDTH - 1 && maze[newX][newY] == 1) {
                maze[newX][newY] = 0; // 挖掘
                maze[current.x + directions[random][0]][current.y + directions[random][1]] = 0; // 中間設空
                queue[rear++] = (Node){newX, newY}; // 加入新的點到 BFS 隊列
            }
        }
    }
    
    // 檢查是否能達到終點
    if(isReachable == 0){
        Node minDistance = searchMinDistance(queue, front);
        breakWall(maze, minDistance);
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

// 尋找離終點最近的點
Node searchMinDistance(Node queue[MAX_QUEUE_SIZE], int front){
    Node result = {1, 1};
    int minDistance = HEIGHT + WIDTH;
    for(int i = 0; i < front; i++){
        int distance = abs(queue[i].x - (WIDTH - 2)) + abs(queue[i].y - (HEIGHT - 2));
        if(distance <= minDistance){
            minDistance = distance;
            result = (Node){queue[i].x, queue[i].y};
        }
    }
    return result;
}

// 破壞離終點最近的點與終點中間的牆壁
void breakWall(int maze[HEIGHT][WIDTH], Node minDistance){
    for(int col = WIDTH - 3; col >= minDistance.y; col--){
        maze[HEIGHT - 2][col] = 0;
    }
    for(int row = HEIGHT - 3; row >= minDistance.x; row--){
        maze[row][minDistance.y] = 0;
    }
}