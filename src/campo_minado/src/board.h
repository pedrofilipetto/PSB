#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>
#include "cell.h"

// Config do PDF: 5x5 e 3 bombas
#define BOARD_ROWS  5
#define BOARD_COLS  5
#define BOARD_MINES 3

typedef struct {
    int rows, cols, mines;
    Cell **grid;         // grid[rows][cols]
} Board;

// ciclo de vida
bool board_init(Board *b, int rows, int cols, int mines);
void board_free(Board *b);

// preparação do tabuleiro
void board_place_mines(Board *b, unsigned int seed);
void board_count_adjacents(Board *b);

// operações
bool board_in_bounds(const Board *b, int r, int c);
bool board_toggle_flag(Board *b, int r, int c);
bool board_reveal(Board *b, int r, int c, int *newly_revealed); // true se explodiu
int  board_hidden_nonmine_left(const Board *b);

#endif
