#include <stdio.h>

int main() {
   double x,y,z,total;
   
   scanf("%lf %lf %lf", &x, &y, &z);

   if (x + y > z && x + z > y && y + z> x){
    if(x == y && y == z) {
      printf("EQUILATERO\n");
    }
    if (x == y || y == z || x == z) {
      printf("ISOSCELES\n");
    }
    if (x != y && y != z) {
      printf("ESCALENO\n");
    }
   } else {
      printf("NAO EH TRIANGULO\n");
   }
   
   return 0;
}