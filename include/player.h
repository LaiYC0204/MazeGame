#ifndef PLAYER_H
#define PLAYER_H

#include "maze.h" // 因為玩家要與迷宮互動，所以需要知道迷宮的資料結構

// 玩家結構
typedef struct {
    int x;
    int y;
} Player;

// 函數原型
int movePlayer(int maze[HEIGHT][WIDTH], Player *player, char direction);

#endif