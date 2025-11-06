#ifndef IO_H
#define IO_H

#include <stdbool.h>
#include "board.h"

void io_print_board(const Board *b, bool reveal_all); // imprime + números/bandeiras
void io_prompt(void);                                 // mostra prompt "comando> "
bool io_parse_command(char *line, char *op, int *r, int *c); // op: 'r','f','q'

#endif
