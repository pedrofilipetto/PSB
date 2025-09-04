#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char nomeArquivo[18];
    char comando[50];
    char arquivoTemp[] = "decoded.bin";
    FILE *arquivo;
    int quantidade;
    int valor;
    long long somatorio = 0;
    
    scanf("%17s", nomeArquivo);
    
    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("ARQUIVO INEXISTENTE\n");
        return 0;
    }
    fclose(arquivo);
    
    sprintf(comando, "base64 -d %s > %s", nomeArquivo, arquivoTemp);
    system(comando);
    
    arquivo = fopen(arquivoTemp, "rb");
    
    fread(&quantidade, sizeof(int), 1, arquivo);
    
    for (int i = 0; i < quantidade; i++) {
        fread(&valor, sizeof(int), 1, arquivo);
        somatorio += valor;
    }
    
    printf("%lld\n", somatorio);
    
    fclose(arquivo);
    remove(arquivoTemp);
    
    return 0;
}
