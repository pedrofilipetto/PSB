#include <stdio.h>

int main() {
    int n;
    int i, j, valor;
    long int fatorial;

    printf("Digite a quantidade de numeros que voce quer calcular o fatorial: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Digite um numero inteiro e positivo: ");
        scanf("%d", &valor);

        fatorial = 1;
        for (j = 1; j <= valor; j++) {
            fatorial *= j;
        }
        
        printf("Valor lido: %d, Fatorial %ld\n", valor, fatorial);
    }
    
    return 0;    
}