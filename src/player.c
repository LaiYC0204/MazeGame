#include <stdio.h>
#include "player.h"

// 實現玩家移動邏輯
int movePlayer(int maze[HEIGHT][WIDTH], Player *player, char direction, int *finish) {
    int newX = player->x, newY = player->y;

    // 根據輸入方向改變位置
    if (direction == 'w') newX--; // 上
    if (direction == 's') newX++; // 下
    if (direction == 'a') newY--; // 左
    if (direction == 'd') newY++; // 右

    // 檢查新位置是否有效
    if (maze[newX][newY] == 0) {
        maze[player->x][player->y] = 0;
        player->x = newX;
        player->y = newY;
        maze[newX][newY] = 2;
        return 1; // 移動成功
    }else if (maze[newX][newY] == 3)
    {
        printf("Victory");
        *finish = 0;
    }
    
    return 0; // 移動失敗
}
