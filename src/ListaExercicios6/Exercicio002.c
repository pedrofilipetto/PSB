#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa em C que, inicialmente, leia um limite
inferior (valor inteiro), um limite superior (valor
inteiro), um tamanho de vetor de inteiros (valor inteiro)
e todos os elementos desse vetor de inteiros. Os elementos
do vetor devem ser armazenados em um vetor alocado dinamicamente,
uma vez que nao está definido qual
o tamanho maximo deste vetor. A seguir, crie um novo vetor,
também alocado dinamicamente, que contenha
apenas os elementos do vetor lido cujos valores sejam maiores
ou iguais ao limite inferior lido e menores ou iguais
ao limite superior lido. Ordene este novo vetor e mostre
o novo vetor ordenado, preferencialmente, em linhas
com 10 valores no maximo em cada linha. Este programa deve
obrigatoriamente utilizar alocacao¸ dinamica e toda
memoria alocada dinamicamente deve ser explicitamente
desalocada.
*/

void quicksort(int data[], int tam);
void _qsort(int data[], int p, int r);
int partition(int data[], int p, int r);
void swap(int data[], int p1, int p2);

void quicksort(int data[], int tam) {
    _qsort(data, 0, tam - 1);
}

void _qsort(int data[], int p, int r) {
    if (p < r) {
        int q = partition(data, p, r);
        _qsort(data, p, q - 1);
        _qsort(data, q + 1, r);
    }
}

int partition(int data[], int p, int r) {
    int q = p;
    for (int j = p; j < r; j++) {
        if (data[j] <= data[r]) {
            swap(data, j, q);
            q++;
        }
    }
    swap(data, r, q);
    return q;
}

void swap(int data[], int p1, int p2) {
    int tmp = data[p1];
    data[p1] = data[p2];
    data[p2] = tmp;
}

void printVetor(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    if (tamanho % 10 != 0) {
        printf("\n");
    }
}

int main()
{

    int limiteInferior, limiteSuperior, tamanho;
    int *vetorOriginal = NULL;
    int *vetorOrdenado = NULL;
    int contadorOrdenado = 0;

    scanf("%d", &limiteInferior);

    scanf("%d", &limiteSuperior);

    scanf("%d", &tamanho);

    if (tamanho <= 0){
        return 1;
    }

    vetorOriginal = (int *)malloc(tamanho * sizeof(int));
    if (vetorOriginal == NULL){
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetorOriginal[i]);
    }

    for (int i = 0; i < tamanho; i++) {
        if (vetorOriginal[i] >= limiteInferior && vetorOriginal[i] <= limiteSuperior) {
            contadorOrdenado++;
        }
    }
    
    if (contadorOrdenado == 0) {
        free(vetorOriginal);
        return 0;
    }
    
    vetorOrdenado = (int*)malloc(contadorOrdenado * sizeof(int));
    if (vetorOrdenado == NULL) {
        free(vetorOriginal);
        return 1;
    }

    int indice = 0;
    for (int i = 0; i < tamanho; i++) {
        if (vetorOriginal[i] >= limiteInferior && vetorOriginal[i] <= limiteSuperior) {
            vetorOrdenado[indice] = vetorOriginal[i];
            indice++;
        }
    }

    quicksort(vetorOrdenado, contadorOrdenado);
    
    printVetor(vetorOrdenado, contadorOrdenado);

    free(vetorOriginal);
    free(vetorOrdenado);

    return 0;
}
