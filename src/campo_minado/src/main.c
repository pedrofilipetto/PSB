#include <stdio.h>
#include "game.h"

int main(void) {
    Game g;
    char nome[64];

    printf("==== CAMPO MINADO ====\n");
    printf("Digite seu nome: ");
    if (!fgets(nome, sizeof(nome), stdin)) return 1;
    // remover \n
    for (char *p = nome; *p; ++p) if (*p == '\n') *p = '\0';

    game_start(&g, nome);
    if (g.running)
        game_loop(&g);

    printf("\nObrigado por jogar!\n");
    return 0;
}
