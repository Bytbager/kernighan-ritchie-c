/*
Упражнение:
Напишите функцию invert(х, р, n), возвращающую значение x с инвертированными
n битами, начиная с позиции p (остальные биты не изменяются).
*/
#include <stdio.h>
#include <limits.h>

#define INT_BITS sizeof(int) * CHAR_BIT

unsigned invert(unsigned x, unsigned p, unsigned n) {
    unsigned mask = n < INT_BITS ? ~(~0 << n) : ~0;
    unsigned position_mask = mask << (p - 1);
    unsigned res = x & ~position_mask;
    res |= (x & position_mask) ^ position_mask;
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
    unsigned x = 0b10101010101010101010101010101010;
    unsigned p = 1;
    unsigned n = 32;
    printf("Изначальное число: ");
    print_bits(x);
    printf("Нужно инвертировать %d битов, начиная с %d позиции.\nРезультат: ", n, p);
    print_bits(invert(x, p, n));
    return 0;
}