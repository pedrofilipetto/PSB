//Função para que recebe caracterese e verifica se é palíndromo
int eh_palindromo(char *s) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }
    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (s[left] != s[right]) return 0;
        left++;
        right--;
    }
    return 1;
}
