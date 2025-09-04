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