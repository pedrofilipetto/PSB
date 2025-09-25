#include <stdio.h>

int main() {
    unsigned int value;
    int bit_pos;
    int bit_value;

    scanf("%u %d", &value, &bit_pos);

    bit_value = (value >> bit_pos) & 1;

    printf("%d\n", bit_value);

    return 0;
}