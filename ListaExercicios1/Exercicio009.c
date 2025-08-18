#include <stdio.h>

int main() {
    int n;
    int i, j, valor;
    long int fatorial;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &valor);

        fatorial = 1;
        for (j = 1; j <= valor; j++) {
            fatorial *= j;
        }
        
        printf("%ld %ld\n", valor, fatorial);
    }
    
    return 0;    
}