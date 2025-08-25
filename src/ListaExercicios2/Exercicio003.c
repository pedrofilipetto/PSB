#include <stdio.h>
#include <stdbool.h>
#define MAX 100
/*
Arquivo: Exercicio003 - Lista 2
Autor: Pedro Castiglia Filipetto
*/

int conta_repetidos(int *vet, int tam);

int main() {
    int vet[MAX], tam;
    scanf("%d", &tam);
    if ( tam > MAX )
        return 1;
    for (int i=0; i < tam; ++i)
        scanf("%d", &vet[i]);
    printf("%d\n", conta_repetidos(vet, tam));
    return 0;
}

int conta_repetidos(int *vet, int tam) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vet[j] > vet[j+1]) {
                unsigned temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
            }
        }
    }
    
    unsigned count = 0;
    int last_counted = -1;

    for (int i = 1; i < tam; i++) {
        if (vet[i] == vet[i-1] && vet[i] != last_counted) {
            count++;
            last_counted = vet[i];
        }
    }

    return count;
}