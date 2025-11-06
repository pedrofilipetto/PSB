#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

typedef struct { int r, c; } P;

static const int DR[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
static const int DC[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

bool board_in_bounds(const Board *b, int r, int c) {
    return r >= 0 && r < b->rows && c >= 0 && c < b->cols;
}

bool board_init(Board *b, int rows, int cols, int mines) {
    b->rows = rows; b->cols = cols; b->mines = mines;
    b->grid = (Cell**) malloc(rows * sizeof(Cell*));
    if (!b->grid) return false;
    for (int i = 0; i < rows; ++i) {
        b->grid[i] = (Cell*) calloc(cols, sizeof(Cell));
        if (!b->grid[i]) {
            for (int k = 0; k < i; ++k) free(b->grid[k]);
            free(b->grid); b->grid = NULL;
            return false;
        }
    }
    return true;
}

void board_free(Board *b) {
    if (!b || !b->grid) return;
    for (int i = 0; i < b->rows; ++i) free(b->grid[i]);
    free(b->grid);
    b->grid = NULL;
}

void board_place_mines(Board *b, unsigned int seed) {
    srand(seed);
    int placed = 0;
    while (placed < b->mines) {
        int r = rand() % b->rows;
        int c = rand() % b->cols;
        if (!b->grid[r][c].has_mine) {
            b->grid[r][c].has_mine = true;
            placed++;
        }
    }
}

void board_count_adjacents(Board *b) {
    for (int r = 0; r < b->rows; ++r) {
        for (int c = 0; c < b->cols; ++c) {
            if (b->grid[r][c].has_mine) {
                b->grid[r][c].adj = -1;
                continue;
            }
            int cnt = 0;
            for (int k = 0; k < 8; ++k) {
                int nr = r + DR[k], nc = c + DC[k];
                if (board_in_bounds(b, nr, nc) && b->grid[nr][nc].has_mine) cnt++;
            }
            b->grid[r][c].adj = cnt;
        }
    }
}

bool board_toggle_flag(Board *b, int r, int c) {
    if (!board_in_bounds(b, r, c)) return false;
    Cell *cell = &b->grid[r][c];
    if (cell->revealed) return false;
    cell->flagged = !cell->flagged;
    return true;
}

/**
 * Revela uma célula. Retorna true se EXPLODIU.
 * Se adj==0, faz flood BFS revelando vizinhos.
 * Em newly_revealed, devolve quantas novas células foram abertas.
 */
bool board_reveal(Board *b, int r, int c, int *newly_revealed) {
    if (newly_revealed) *newly_revealed = 0;
    if (!board_in_bounds(b, r, c)) return false;

    Cell *start = &b->grid[r][c];
    if (start->flagged || start->revealed) return false;

    if (start->has_mine) {
        start->revealed = true; // mostra a bomba estourada
        if (newly_revealed) (*newly_revealed)++;
        return true; // explodiu
    }

    // BFS para flood de zeros
    int cap = b->rows * b->cols;
    P *q = (P*) malloc(sizeof(P) * cap);
    int qh = 0, qt = 0;

    q[qt++] = (P){r, c};
    while (qh < qt) {
        P cur = q[qh++];
        Cell *cell = &b->grid[cur.r][cur.c];
        if (cell->revealed || cell->flagged) continue;
        cell->revealed = true;
        if (newly_revealed) (*newly_revealed)++;

        if (cell->adj == 0) {
            for (int k = 0; k < 8; ++k) {
                int nr = cur.r + DR[k], nc = cur.c + DC[k];
                if (!board_in_bounds(b, nr, nc)) continue;
                Cell *nb = &b->grid[nr][nc];
                if (!nb->revealed && !nb->flagged && !nb->has_mine) {
                    q[qt++] = (P){nr, nc};
                }
            }
        }
    }

    free(q);
    return false; // não explodiu
}

int board_hidden_nonmine_left(const Board *b) {
    int total = b->rows * b->cols - b->mines;
    int revealed = 0;
    for (int r = 0; r < b->rows; ++r)
        for (int c = 0; c < b->cols; ++c)
            if (b->grid[r][c].revealed && !b->grid[r][c].has_mine) revealed++;
    return total - revealed;
}
