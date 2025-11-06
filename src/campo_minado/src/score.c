#include <stdio.h>
#include <string.h>
#include "score.h"

typedef struct {
    double value;
    char name[64];
} Score;

static Score scores[MAX_SCORES];
static int count = 0;

void load_scores(void) {
    count = 0;
    FILE *f = fopen(SCORE_FILE, "r");
    if (!f) return;

    while (count < MAX_SCORES &&
           fscanf(f, " %lf;%63[^\n]\n", &scores[count].value, scores[count].name) == 2) {
        count++;
    }
    fclose(f);
}

void insert_score(const char *name, double value) {
    if (count < MAX_SCORES) {
        scores[count].value = value;
        strncpy(scores[count].name, name, 63);
        scores[count].name[63] = '\0';
        count++;
    } else {
        if (value > scores[count-1].value)
            scores[count-1].value = value;
    }

    /* ordenação decrescente simples */
    for (int i = 0; i < count; i++)
        for (int j = 0; j + 1 < count; j++)
            if (scores[j].value < scores[j+1].value) {
                Score tmp = scores[j];
                scores[j] = scores[j+1];
                scores[j+1] = tmp;
            }

    if (count > MAX_SCORES) count = MAX_SCORES;
}

void save_scores(void) {
    FILE *f = fopen(SCORE_FILE, "w");
    if (!f) return;
    for (int i = 0; i < count; i++)
        fprintf(f, "%.2f;%s\n", scores[i].value, scores[i].name);
    fclose(f);
}

void show_scores(void) {
    if (count == 0) {
        printf("(sem pontuações ainda)\n");
        return;
    }
    printf("\n===== RANKING =====\n");
    for (int i = 0; i < count; i++)
        printf("%2d) %-15s %.2f\n", i+1, scores[i].name, scores[i].value);
}
