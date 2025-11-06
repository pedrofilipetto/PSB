#ifndef CELL_H
#define CELL_H

#include <stdbool.h>

typedef struct {
    bool has_mine;
    bool revealed;
    bool flagged;
    int  adj;       // número de minas adjacentes (0..8)
} Cell;

#endif
