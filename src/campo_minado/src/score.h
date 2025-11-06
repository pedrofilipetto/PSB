#ifndef SCORE_H
#define SCORE_H

#define MAX_SCORES 10
#define SCORE_FILE "scores.txt"

void load_scores(void);
void insert_score(const char *name, double value);
void save_scores(void);
void show_scores(void);

#endif
