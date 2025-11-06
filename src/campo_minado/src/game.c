#include <stdio.h>
#include <string.h>
#include <time.h>
#include "game.h"
#include "IO.h"
#include "score.h"

void game_start(Game *g, const char *player) {
    strncpy(g->player, player, sizeof(g->player) - 1);
    g->player[sizeof(g->player) - 1] = '\0';

    if (!board_init(&g->board, BOARD_ROWS, BOARD_COLS, BOARD_MINES)) {
        fprintf(stderr, "Erro ao inicializar tabuleiro.\n");
        g->running = false;
        return;
    }

    unsigned int seed = (unsigned int)time(NULL);
    board_place_mines(&g->board, seed);
    board_count_adjacents(&g->board);

    g->revealed_count = 0;
    g->running = true;
}

double game_score(const Game *g) {
    int total = g->board.rows * g->board.cols - g->board.mines;
    if (total == 0) return 0.0;
    return 100.0 * (double)g->revealed_count / (double)total;
}

void game_loop(Game *g) {
    char line[64];
    char op;
    int r, c;

    printf("Bem-vindo(a), %s!\n", g->player);
    printf("Tabuleiro %dx%d com %d bombas.\n", BOARD_ROWS, BOARD_COLS, BOARD_MINES);
    printf("Comandos: r i j (revelar), f i j (bandeira), q (sair)\n\n");

    bool exploded = false;

    while (g->running) {
        ui_print_board(&g->board, false);
        io_prompt();

        if (!fgets(line, sizeof(line), stdin)) break;
        if (!io_parse_command(line, &op, &r, &c)) {
            printf("Comando inválido!\n");
            continue;
        }

        if (op == 'q') {
            printf("Você desistiu!\n");
            break;
        } else if (op == 'f') {
            board_toggle_flag(&g->board, r, c);
        } else if (op == 'r') {
            int newly = 0;
            exploded = board_reveal(&g->board, r, c, &newly);
            g->revealed_count += newly;

            if (exploded) {
                printf("\n BOOM! Você pisou em uma bomba!\n");
                io_print_board(&g->board, true);
                printf("Fim de jogo.\n");
                g->running = false;
                break;
            }

            if (board_hidden_nonmine_left(&g->board) == 0) {
                printf("\n Parabéns, você venceu!\n");
                io_print_board(&g->board, true);
                double score = game_score(g);
                printf("Seu escore: %.2f\n", score);

                // Atualiza ranking
                ScoreTable t;
                score_load(SCORE_FILE, &t);
                score_insert(&t, g->player, score);
                score_save(SCORE_FILE, &t);
                printf("\nRanking atualizado:\n");
                score_print(&t);

                g->running = false;
                break;
            }
        }
    }

    board_free(&g->board);
}
