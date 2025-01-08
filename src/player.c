#include "player.h"

// 實現玩家移動邏輯
int movePlayer(int maze[HEIGHT][WIDTH], Player *player, char direction) {
    int newX = player->x, newY = player->y;

    // 根據輸入方向改變位置
    if (direction == 'w') newX--; // 上
    if (direction == 's') newX++; // 下
    if (direction == 'a') newY--; // 左
    if (direction == 'd') newY++; // 右

    // 檢查新位置是否有效
    if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT && maze[newY][newX] == 0) {
        maze[player->x][player->y] = 0;
        player->x = newX;
        player->y = newY;
        maze[player->x][player->y] = 1;
        return 1; // 移動成功
    }
    return 0; // 移動失敗
}
