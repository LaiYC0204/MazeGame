#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "player.h"
#include "game_state.h"

int main() {
    initializeGameState(); // 初始化遊戲狀態
    generateMaze();
    Player *player = getPlayer();
    int *maze = getMaze();

    char input;
    while (isGameRunning()) {
        printMaze(player->x, player->y);
        printf("\nMove (w/a/s/d): ");
        scanf(" %c", &input);
        movePlayer(maze, input);
        if(checkWinCondition(player->x, player->y)){
            stopGame();
        } 
    }
    return 0;
}
