#include <stdio.h>
#include "player.h"

// 實現玩家移動邏輯
int movePlayer(int maze[HEIGHT][WIDTH], Player *player, char direction, int *finish) {
    int newX = player->x, newY = player->y;

    // 根據輸入方向改變位置
    if (direction == 'w') newY--; // 上
    if (direction == 's') newY++; // 下
    if (direction == 'a') newX--; // 左
    if (direction == 'd') newX++; // 右

    // 檢查新位置是否有效
    if (maze[newY][newX] == 0) {
        maze[player->y][player->x] = 0;
        player->x = newX;
        player->y = newY;
        maze[player->y][player->x] = 2;
        return 1; // 移動成功
    }else if (maze[newY][newX] == 3)
    {
        printf("Victory");
        *finish = 0;
    }
    
    return 0; // 移動失敗
}
