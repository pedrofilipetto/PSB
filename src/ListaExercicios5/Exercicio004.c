#include <stdio.h>

int main() {
    int color_palette_value;
    int green_out, red_out, blue_out;

    scanf("%d", &color_palette_value);

    green_out = color_palette_value & 0xE0;

    red_out = (color_palette_value & 0x1C) << 3;

    blue_out = (color_palette_value & 0x03) << 6;

    printf("%d %d %d\n", green_out, red_out, blue_out);

    return 0;
}