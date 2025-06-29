#include <stdio.h>

/* bitcount: подсчет единиц в х */
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}

int main() {
    printf("count: %d\n", bitcount(0b11110));
    return 0;
}