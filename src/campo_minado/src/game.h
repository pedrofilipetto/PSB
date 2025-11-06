#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "board.h"

typedef struct {
    char  player[64];
    Board board;
    int   revealed_count;
    bool  running;
} Game;

void   game_start(Game *g, const char *player);     // inicia 5x5 c/ 3 minas
void   game_loop(Game *g);                          // loop de comandos (r/f/q)
double game_score(const Game *g);                   // 100 * reveladas / (25-3)

#endif
