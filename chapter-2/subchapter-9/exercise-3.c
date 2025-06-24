/*
Упражнение:
Напишите функцию rightrot(х, n), которая циклически сдвигает x вправо на n
разрядов.
*/
#include <stdio.h>
#include <limits.h>

#define INT_BITS sizeof(int) * CHAR_BIT

unsigned bit_length(unsigned x);

unsigned rightrot(unsigned x, unsigned n) {
    unsigned bit_len = bit_length(x);
    for (int i = 0; i < n; i++) {
        unsigned tmp = (x & 1) << (bit_len - 1);
        x >>= 1;
        x |= tmp;
    }
    return x;
}

/* bit_length: возвращает количесвто бит, которые используются в числе x */
unsigned bit_length(unsigned x) {
    unsigned res = 0;
    for (int i = 0; i < INT_BITS; i++, x >>= 1) if (x & 1) res = i + 1;
    return res;
}

/* print_bits: печатает число num в двоичном виде */
void print_bits(unsigned num) {
    unsigned mask = 1 << (INT_BITS - 1);
    int print_flag = 0;
    printf("0b");
    for (int i = 0; i < INT_BITS; i++) {
        int bit = num & mask ? 1 : 0;
        if (!print_flag) print_flag = bit;
        if (print_flag) printf("%d", bit);
        num <<= 1;
    }
    printf("\n");
}

int main() {
    unsigned x = 0b11011;
    unsigned n = 3;
    printf("Изначальное число: ");
    print_bits(x);
    printf("Нужно циклически сдвинуть вправо число на %d позиций.\nРезультат: ", n);
    print_bits(rightrot(x, n));
    return 0;
}