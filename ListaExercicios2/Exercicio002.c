#include <stdio.h>

int main(unsigned seg, unsigned *h, unsigned *m, unsigned *s) {
    unsigned seg, h, m, s;
    scanf("%u", &seg);
    hms(seg, &h, &m, &s);
    printf("%u %u %u\n", h, m, s);
    return 0;    
}

void hms(unsigned seg, unsigned *h, unsigned *m, unsigned *s);
    int main() {
    unsigned seg, h, m, s;
    scanf("%u", &seg);
    hms(seg, &h, &m, &s);
    printf("%u %u %u\n", h, m, s);
    return 0;
}