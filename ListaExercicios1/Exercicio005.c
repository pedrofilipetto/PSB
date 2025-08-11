#include <stdio.h>

int main() {
   double x,y,z,total;
   
   printf("Digite os tamanhos dos lados do triangulo: ");
   scanf("%lf %lf %lf", &x, &y, &z);

   if (x + y > z && x + z > y && y + z> x)   {
    printf("Eh triangulo!\n");
    if(x == y && y == z) {
      printf("Equilatero\n");
    }
    if (x == y || y == z || x == z) {
      printf("Isoceles");
    }
    if (x != y && y != z) {
      printf("Escaleno");
    }
   } else {
      printf("Nao eh triangulo!\n");
   }
   

   return 0;
}