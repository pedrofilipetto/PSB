#ifndef BOARD_H
#define BOARD_H

#define ROWS 5
#define COLS 5
#define MINES 3

void clear_board(void);
void place_mines(void);
void count_adjacents(void);
void print_board(int reveal_all);
int  reveal_cell(int r, int c, int *explodiu);
void toggle_flag(int r, int c);
int  hidden_without_bomb(void);

#endif
