#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "player.h"

void initializeGameState();
int checkWinCondition(int playerX, int playerY);
int isGameRunning();
void stopGame();

#endif
