#include <stdio.h>
#include "game_state.h"

static int running; // 模組內部的靜態變數

void initializeGameState() {
    running = 1; // 初始化遊戲狀態
}

int checkWinCondition(int playerX, int playerY) {
    // 判斷玩家是否到達終點
    if (playerX == HEIGHT - 2 && playerY == WIDTH - 2) {
        printf("You are Winner!!\n");
        return 1; // 表示已經獲勝
    }
    return 0; // 尚未獲勝
}

int isGameRunning() {
    return running;
}

void stopGame() {
    running = 0;
}