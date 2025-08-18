#include <stdio.h>

int main() {
   double x,y,z;
   
   scanf("%lf %lf %lf", &x, &y, &z);

   if (x + y <= z || x + z <= y || y + z <= x){
    printf("NAO EH TRIANGULO\n");
   } else {
    if(x == y && y == z) {
      printf("EQUILATERO\n");
    }
    else if (x == y || y == z || x == z) {
      printf("ISOSCELES\n");
    }
    else {
      printf("ESCALENO\n");
    }
  }
   
   return 0;
}