#include <stdio.h>
#include <math.h>


int main() {
    double a, b, c;
    double delta, r1, r2;

    scanf("%lf %lf %lf", &a, &b, &c);

    delta = b*b - 4*a*c;

    if (delta < 0) {
        printf("0\n");
    }
    else if (delta == 0) {
        r1 = -b / (2*a);
        printf("1 %.4lf\n", r1);
    } 
    else {
        r1 = (-b + sqrt(delta)) / (2*a);
        r2 = (-b - sqrt(delta)) / (2*a);
        printf ("2 %.4lf %.4lf\n", r1, r2);
    }

    return 0;
}