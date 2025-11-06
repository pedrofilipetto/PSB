#include <stdio.h>
#include <string.h>
#include "board.h"
#include "score.h"

static double calculate_score(int revealed) {
    int total = ROWS * COLS - MINES;
    return 100.0 * revealed / total;
}

void play_minesweeper(void) {
    char name[64];
    printf("==== CAMPO MINADO ====\n");
    printf("Digite seu nome: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    clean_board();
    place_bombs();
    count_adjacent();

    int exploded = 0, revealed = 0;
    char command;
    int r, c;

    while (!exploded) {
        print_board(0);
        printf("Comando (r i j / f i j / q): ");
        if (scanf(" %c", &command) != 1) break;
        if (command == 'q') break;

        if (command == 'r' && scanf("%d %d", &r, &c) == 2) {
            int novos = reveal_cell(r, c, &exploded);
            revealed += novos;
            if (exploded) {
                printf("\n Bomba! Fim de jogo.\n");
                print_board(1);
                break;
            }
            if (hidden_without_bomb() == 0) {
                printf("\n Parabéns, você venceu!\n");
                print_board(1);
                double score = calculate_score(revealed);
                printf("Seu escore: %.2f\n", score);

                load_scores();
                insert_score(name, score);
                save_scores();
                show_scores();
                break;
            }
        } else if (command == 'f' && scanf("%d %d", &r, &c) == 2) {
            toggle_flag(r, c);
        }
    }
}
