/*
Упражнение:
Напишите функцию setbits(x, p, n, y), возвращающую значение x, в котором n
битов, начиная с p-й позиции, заменены на n правых разрядов из y (остальные биты не изменяются).
*/
#include <stdio.h>
#include <limits.h>

#define INT_BITS sizeof(int) * CHAR_BIT

unsigned setbits(const unsigned x, const int p, const int n, const unsigned y) {
    unsigned mask = ~(~0 << n);
    unsigned position_mask = ~(mask << (p - 1));
    unsigned res = x & position_mask;
    res |= (y & mask) << (p - 1);
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
    unsigned x = 0b1111000011110000;
    unsigned y = 0b11110000;
    unsigned n = 8;
    unsigned p = 5;
    unsigned res = setbits(x, p, n, y);
    printf("Изначальное число: ");
    print_bits(x);
    printf("Второе число: ");
    print_bits(y);
    printf("Нужно %d правых битов числа y подставить в число x, начиная с %d позиции, остальные биты не менять\nРезультат: ", n, p);
    print_bits(res);
    return 0;
}