#ifndef SCORE_H
#define SCORE_H

#include <stddef.h>

#define MAX_SCORES 10
#define SCORE_FILE "scores.txt"

typedef struct {
    double value;       // quanto menor, melhor (ou conforme o PDF exigir)
    char   name[64];
} ScoreEntry;

typedef struct {
    ScoreEntry entries[MAX_SCORES];
    size_t     count;
} ScoreTable;

void score_load(const char *path, ScoreTable *t);
void score_insert(ScoreTable *t, const char *name, double value); // insere ordenado e trunca em 10
void score_save(const char *path, const ScoreTable *t);
void score_print(const ScoreTable *t);

#endif
