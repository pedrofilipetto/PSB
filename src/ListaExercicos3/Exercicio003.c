/*
Considere uma linha no formato CSV (Comma-Separated Values) que use como separador o caractere ’;’ (ponto-virgula) 
e que contenha as seguintes informacoes sobre uma pessoa (exatamente na seguinte ordem): nome (ate 40 caracteres uteis), 
idade (expressa como um valor inteiro), peso (em kg, expresso como um numero real, usando ponto como separador de casas decimais) 
e altura (em metros, expressa como um numero real, usando ponto como separador de casas decimais). 
Escreva um programa em C que leia uma linha nesse formato CSV, calculando o IMC (Indice de Massa Corporal) dessa Pessoa, 
usando a seguinte formula:
IMC = Peso / Altura * Altura
Mostre o resultado no seguinte formato: nome da pessoa, texto “: ” e IMC dessa pessoa (com 4 casas decimais).
*/
#include <stdio.h>
#include <string.h>

int main() {
 
    char linha_csv[100]; 
    
    char nome[41];    
    int idade;
    float peso;
    float altura;
    float imc;
  
    fgets(linha_csv, sizeof(linha_csv), stdin);

    sscanf(linha_csv, "%[^;];%d;%f;%f", nome, &idade, &peso, &altura);

    if (altura > 0) {
        imc = peso / (altura * altura);
    } else {
        imc = 0;
    }

    printf("%s; %.4f\n", nome, imc);

    return 0;
}
