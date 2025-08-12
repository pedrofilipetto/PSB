#include <stdio.h>
/*Escrever um programa que le um valor inteiro n, maior do que 0 (zero), e que mostra todos os divisores deste
numero, desconsiderando 1 e o proprio numero como divisores, ou um asterisco (“*”) caso o numero nao possua 
divisores.
*/

int main() {
    int x;
    int y;

    printf("Insira um numero: ");
    scanf("%d", &x);
    int hasDivisor = 0;
    if (x > 0) {
        printf("Divisores de %d: ", x);
        for (y = 2; y < x; y++) {
            if (x % y == 0) {
                printf("%d ", y);
                hasDivisor = 1;
            }
        }
        if (!hasDivisor) {
            printf("*\n");
        }
    } else {
        printf("O numero deve ser maior que 0.\n");
    }
}