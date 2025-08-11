#include <stdio.h>

int main() {
     double f, c;

    printf("Digite os graus Fahrenheit: ");
    scanf("%lf", &f);
    c = 5.0/9.0 * (f - 32.0);
    
    printf("O resultado em Celsius eh: %lf\n", c);
    
    return 0;
}