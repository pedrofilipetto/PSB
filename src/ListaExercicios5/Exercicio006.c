#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    int zero_count = 0;
    int msb_pos = -1;
    int i;

    for (i = (sizeof(int) * CHAR_BIT) - 1; i >= 0; i--) {
        if ((n >> i) & 1) {
            msb_pos = i;
            break;
        }
    }

    if (msb_pos != -1) {
        for (i = msb_pos - 1; i >= 0; i--) {
            if (!((n >> i) & 1)) {
                zero_count++;
            }
        }
    }

    printf("%d\n", zero_count);

    return 0;
}