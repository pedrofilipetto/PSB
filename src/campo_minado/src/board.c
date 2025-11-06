#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

static int board[ROWS][COLS];
static int revealed[ROWS][COLS];
static int flagged[ROWS][COLS];

static int in_bounds(int r, int c) {
    return r >= 0 && r < ROWS && c >= 0 && c < COLS;
}

void clear_board(void) {
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++) {
            board[r][c] = 0;
            revealed[r][c] = 0;
            flagged[r][c] = 0;
        }
}

void place_mines(void) {
    int placed = 0;
    srand((unsigned)time(NULL));
    while (placed < MINES) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (board[r][c] != -1) {
            board[r][c] = -1;
            placed++;
        }
    }
}

void count_adjacents(void) {
    int dr[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
    int dc[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (board[r][c] == -1) continue;
            int soma = 0;
            for (int k = 0; k < 8; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (in_bounds(nr, nc) && board[nr][nc] == -1)
                    soma++;
            }
            board[r][c] = soma;
        }
    }
}

void print_board(int reveal_all) {
    printf("    ");
    for (int c = 0; c < COLS; c++) printf("%2d ", c);
    printf("\n");

    for (int r = 0; r < ROWS; r++) {
        printf("%2d |", r);
        for (int c = 0; c < COLS; c++) {
            char ch = 'X';
            if (reveal_all || revealed[r][c]) {
                if (board[r][c] == -1) ch = '*';
                else if (board[r][c] == 0) ch = ' ';
                else ch = (char)('0' + board[r][c]);
            } else if (flagged[r][c]) {
                ch = '+';
            }
            printf(" %c ", ch);
        }
        printf("|\n");
    }
}

/* Flood recursivo */
int reveal_cell(int r, int c, int *exploded) {
    if (!in_bounds(r, c)) return 0;
    if (revealed[r][c] || flagged[r][c]) return 0;

    revealed[r][c] = 1;
    if (board[r][c] == -1) { *exploded = 1; return 1; }

    int new = 1;
    if (board[r][c] == 0) {
        int dr[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
        for (int k = 0; k < 8; k++)
            new += reveal_cell(r+dr[k], c+dc[k], exploded);
    }
    return new;
}

void toggle_flag(int r, int c) {
    if (in_bounds(r, c) && !revealed[r][c])
        flagged[r][c] = !flagged[r][c];
}

int hidden_without_bomb(void) {
    int total_without_bomb = ROWS * COLS - MINES;
    int revealed_count = 0;
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            if (revealed[r][c] && board[r][c] != -1)
                revealed_count++;
    return total_without_bomb - revealed_count;
}
