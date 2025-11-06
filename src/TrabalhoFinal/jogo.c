#include <stdio.h>
#include <string.h>
#include "jogo.h"

void iniciar_jogo() {
    char nome[100];

    printf("Digite seu nome: ");
    if (fgets(nome, sizeof(nome), stdin) != NULL) {
        size_t len = strlen(nome);
        if (len > 0 && nome[len - 1] == '\n') {
            nome[len - 1] = '\0';
        }
        printf("Bem-vindo(a), %s!\n", nome);
    } else {
        printf("Bem-vindo(a)!\n");
    }

    
}
