#include <stdio.h>

int main() {
     double f, c;

    scanf("%lf", &f);
    c = 5.0/9.0 * (f - 32.0);
    
    printf("%.4lf", c);
    
    return 0;
}