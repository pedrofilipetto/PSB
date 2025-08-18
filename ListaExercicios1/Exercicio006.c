#include <stdio.h>
/*Escrever um programa que le um valor inteiro n, maior do que 0 (zero), e que mostra todos os divisores deste
numero, desconsiderando 1 e o proprio numero como divisores, ou um asterisco (“*”) caso o numero nao possua 
divisores.
*/

int main() {
    int x;

    scanf("%d", &x);
    int hasDivisor = 0;
    if (x > 0) {
        for (int y = 2; y < x; y++) {
            if (x % y == 0) {
                printf("%d ", y);
                hasDivisor = 1;
            }
        }
        if (hasDivisor != 1) {
            printf("*");
        }
    }
}