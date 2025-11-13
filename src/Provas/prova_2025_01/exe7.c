#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n = 5;

    // Vetor com valores a serem copiados
    double v[5] = {4.5, 1.0, 3.0, 2.5, 5.5};

    // Aloca memória dinamicamente para 5 valores
    double *vet = (double *)malloc(5 * sizeof(double));

    // Copia os 5 valores de v para vet
    for (int i = 0; i < 5; i++) {
        vet[i] = v[i];
    }

    // Encontra maior e menor
    double maior = vet[0];
    double menor = vet[0];

    for (int i = 1; i < 5; i++)
    {
        if (vet[i] > maior)
            maior = vet[i];
        if (vet[i] < menor)
            menor = vet[i];
    }

    // Calcula e imprime a diferença
    double diferenca = maior - menor;
    printf("Diferenca: %.2lf\n", diferenca);

    free(vet);

    return 0;
}
