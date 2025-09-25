#include <stdio.h>

int main() {
    int row_byte;
    int i, j;

    for (i = 0; i < 8; i++) {
        scanf("%d", &row_byte);

        for (j = 0; j < 8; j++) {
            if (row_byte & 0x80) {
                printf("X");
            } else {
                printf(".");
            }
            row_byte <<= 1;
        }
        printf("\n");
    }

    return 0;
}