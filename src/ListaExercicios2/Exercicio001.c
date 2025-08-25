#include <stdio.h>
/*
 * Arquivo: Exercicio001 - Lista 2
 * Autor: Pedro Castiglia Filipetto
 
Escreva uma funcao em C para um caixa de banco, que recebe um valor inteiro r (maior ou igual a zero) 
e determina o numero de notas de 100, 50, 10, 5 e 1 reais necessario para pagar a quantia r. 
Faca de forma que o numero ´de notas usado seja o menor poss´ıvel, retornando as quantidades de notas por referencia.
*/
void papelMoeda(
    unsigned r, 
    unsigned *n100, 
    unsigned *n50, 
    unsigned *n10, 
    unsigned *n5, 
    unsigned *n1
);

int main() {
    unsigned r, n100, n50, n10, n5, n1;
    scanf("%u", &r);
    papelMoeda(r, &n100, &n50, &n10, &n5, &n1);
    printf("%u %u %u %u %u\n", n100, n50, n10, n5, n1);
    return 0;
}

void papelMoeda(
    unsigned r, 
    unsigned *n100, 
    unsigned *n50, 
    unsigned *n10, 
    unsigned *n5, 
    unsigned *n1
) {
    unsigned restante = r;
    unsigned notasVal[] = {100, 50, 10, 5, 1};
    unsigned *notas[] = {n100, n50, n10, n5, n1};

    for (int i = 0; i < 5; i++) {
        *(notas[i]) = restante / notasVal[i];
        restante %= notasVal[i];
    }
}