#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "score.h"

static int cmp_desc(const void *a, const void *b) {
    const ScoreEntry *sa = (const ScoreEntry*)a;
    const ScoreEntry *sb = (const ScoreEntry*)b;
    if (sa->value <  sb->value) return 1;   // maior primeiro
    if (sa->value >  sb->value) return -1;
    return strncmp(sa->name, sb->name, sizeof(sa->name));
}

void score_load(const char *path, ScoreTable *t) {
    t->count = 0;
    FILE *f = fopen(path, "r");
    if (!f) {
        // Sem arquivo ainda? Tudo bem: começamos vazio.
        return;
    }

    char line[256];
    while (t->count < MAX_SCORES && fgets(line, sizeof(line), f)) {
        // formato: score;nome
        ScoreEntry e;
        e.name[0] = '\0';
        if (sscanf(line, " %lf ; %63[^\n]", &e.value, e.name) == 2) {
            t->entries[t->count++] = e;
        }
    }
    fclose(f);

    // garante ordenação se o arquivo estiver fora de ordem
    qsort(t->entries, t->count, sizeof(ScoreEntry), cmp_desc);
}

void score_insert(ScoreTable *t, const char *name, double value) {
    // adiciona no fim
    if (t->count < MAX_SCORES) {
        t->entries[t->count].value = value;
        strncpy(t->entries[t->count].name, name, sizeof(t->entries[t->count].name)-1);
        t->entries[t->count].name[sizeof(t->entries[t->count].name)-1] = '\0';
        t->count++;
    } else {
        // só entra se superar o pior (último após ordenar desc)
        // para simplificar, inserimos e depois truncamos
        t->entries[t->count-1].value = value;
        strncpy(t->entries[t->count-1].name, name, sizeof(t->entries[t->count-1].name)-1);
        t->entries[t->count-1].name[sizeof(t->entries[t->count-1].name)-1] = '\0';
    }

    // ordena e trunca em 10
    qsort(t->entries, t->count, sizeof(ScoreEntry), cmp_desc);
    if (t->count > MAX_SCORES) t->count = MAX_SCORES;
}

void score_save(const char *path, const ScoreTable *t) {
    FILE *f = fopen(path, "w");
    if (!f) {
        fprintf(stderr, "Erro ao salvar '%s': %s\n", path, strerror(errno));
        return;
    }
    for (size_t i = 0; i < t->count; ++i) {
        fprintf(f, "%.2f;%s\n", t->entries[i].value, t->entries[i].name);
    }
    fclose(f);
}

void score_print(const ScoreTable *t) {
    if (t->count == 0) {
        printf("(sem pontuações ainda)\n");
        return;
    }
    for (size_t i = 0; i < t->count; ++i) {
        printf("%2zu) %-20s  %.2f\n", i+1, t->entries[i].name, t->entries[i].value);
    }
}
