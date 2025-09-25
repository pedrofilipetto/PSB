#include <stdio.h>

int main() {
    int green_in, red_in, blue_in;
    unsigned char final_color;

    scanf("%d %d %d", &green_in, &red_in, &blue_in);

    unsigned char green_bits = (unsigned char)(green_in >> 5);
    unsigned char red_bits = (unsigned char)(red_in >> 5);
    unsigned char blue_bits = (unsigned char)(blue_in >> 6);

    final_color = (green_bits << 5) | (red_bits << 2) | blue_bits;

    printf("%d\n", final_color);

    return 0;
}