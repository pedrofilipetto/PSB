#include <stdio.h>
/*
Arquivo: Exercicio002 - Lista 2
Autor: Pedro Castiglia Filipetto
*/
void hms(unsigned seg, unsigned *h, unsigned *m, unsigned *s);

int main() {
    unsigned seg, h, m, s;
    scanf("%u", &seg);
    hms(seg, &h, &m, &s);
    printf("%u %u %u\n", h, m, s);
    return 0;
}

void hms(unsigned seg, unsigned *h, unsigned *m, unsigned *s) {
    *h = seg / 3600;
    seg -= *h*3600;
    *m = seg / 60;
    seg -= *m*60;
    *s = seg;
}