#include <stdio.h>
/*Escreva uma funcao em C para um caixa de banco, que recebe um valor inteiro r (maior ou igual a zero) 
e determina o numero de notas de 100, 50, 10, 5 e 1 reais necessario para pagar a quantia r. 
Faca de forma que o numero ´de notas usado seja o menor poss´ıvel, retornando as quantidades de notas por referencia.
*/

void papelMoeda(unsigned r, unsigned *n100, unsigned *n50, unsigned *n10, unsigned *n5, unsigned *n1){
    
    *n100 = r / 100;
	r = r % 100;

    *n50 = r / 50;
	r = r % 50;

    *n10 = r / 10;
	r = r % 10;

    *n5 = r / 5;
	r = r % 5;

    *n1 = r;
}

int main() {
    unsigned r, n100, n50, n10, n5, n1;

    printf("Digite o valor recebido: ");
    scanf("%u", &r);

    papelMoeda(r, &n100, &n50, &n10, &n5, &n1);
    printf("Notas de 100: %u\nNotas de 50: %u\nNotas de 10: %u\nNotas de 5: %u\nNotas de 1: %u\n", n100, n50, n10, n5, n1);

    return 0;
}