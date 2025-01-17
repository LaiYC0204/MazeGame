#include <stdio.h>
#include "player.h"

static Player player = {1, 1};

// 實現玩家移動邏輯
int movePlayer(int *maze, char direction) {
    int newX = player.x, newY = player.y;

    // 根據輸入方向改變位置
    if (direction == 'w') newX--; // 上
    if (direction == 's') newX++; // 下
    if (direction == 'a') newY--; // 左
    if (direction == 'd') newY++; // 右

    // 檢查新位置是否有效
    if (*(maze + newX * WIDTH + newY) == 0 || *(maze + newX * WIDTH + newY) == 3) {
        player.x = newX;
        player.y = newY;
        return 1; // 移動成功
    }
    
    return 0; // 移動失敗
}

Player* getPlayer(){
    return &player;
}