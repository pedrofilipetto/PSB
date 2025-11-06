#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "IO.h"

void ui_print_board(const Board *b, bool reveal_all) {
    // cabeçalho de colunas
    printf("    ");
    for (int c = 0; c < b->cols; ++c) printf("%2d ", c);
    printf("\n");

    for (int r = 0; r < b->rows; ++r) {
        printf("%2d |", r);
        for (int c = 0; c < b->cols; ++c) {
            const Cell *cell = &b->grid[r][c];
            char ch = '#';

            if (reveal_all || cell->revealed) {
                if (cell->has_mine) ch = '*';
                else if (cell->adj == 0) ch = ' ';
                else ch = '0' + cell->adj;
            } else if (cell->flagged) {
                ch = '+';
            } else {
                ch = 'X';
            }
            printf(" %c ", ch);
        }
        printf("|\n");
    }
}

void io_prompt(void) {
    printf("comando (r i j | f i j | q): ");
}

bool io_parse_command(char *line, char *op, int *r, int *c) {
    // aceita: r i j  |  f i j  |  q
    // espaços flexíveis; case-insensitive
    char o;
    int i=-1, j=-1;
    if (sscanf(line, " %c %d %d", &o, &i, &j) == 3) {
        o = (char)tolower((unsigned char)o);
        if (o=='r' || o=='f') {
            *op = o; *r = i; *c = j; return true;
        }
    } else if (sscanf(line, " %c", &o) == 1) {
        o = (char)tolower((unsigned char)o);
        if (o=='q') { *op = o; return true; }
    }
    return false;
}
