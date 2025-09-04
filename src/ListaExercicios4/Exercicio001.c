/*
Escreva um programa em C que, inicialmente, leia o nome de um arquivo (com no maximo 17 caracteres uteis).
A seguir, seu programa devera abrir o arquivo para leitura em modo texto, lendo um numero inteiro,
que corresponde a quantidade de valores inteiros (que aparecem na sequencia dentro desse mesmo arquivo),
e cada um desses valores, calculando e mostrando o somatorio desses valores. Caso o arquivo NAO exista,
seu programa deve imprimir a mensagem "ARQUIVO INEXISTENTE" (encerrando o programa com codigo de sucesso, ou seja, 0).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char nomeArquivo[18];
    FILE *arquivo;
    long long somatorio = 0, valorAtual;
    int quantidadeDeValores;

    scanf("%17s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL)
    {
        printf("ARQUIVO INEXISTENTE\n");
        return 0;
    }

    fscanf(arquivo, "%d", &quantidadeDeValores);

    for (int i = 0; i < quantidadeDeValores; i++)
    {
        fscanf(arquivo, "%lld", &valorAtual);
        somatorio += valorAtual;
    }

    printf("%lld\n", somatorio);

    fclose(arquivo);

    return 0;
}