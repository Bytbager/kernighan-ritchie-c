/*
Упражнение:
Применительно к числам, в представлении которых использован дополнительный код,
выражение х &= (х-1) уничтожает самую правую 1 в х. Объясните, почему. Используйте это наблюдение
при написании более быстрого варианта функции bitcount.

Объяснение:
Самый правый бит числа x, равный 1, в выражениее (x-1) станет равен 0.
Соответственно побитовое И превратит эту единицу в ноль, а т.к. в выражении x &= x-1 мы присваеваем
новое значение числу x, то делать так в цикле в один момент в нем кончатся все единицы и он станет равен нулю
*/
#include <stdio.h>
#include <limits.h>

#define INT_BITS sizeof(int) * CHAR_BIT

unsigned bitcount(unsigned x) {
    unsigned res = 0;
    for (; x != 0; x &= x - 1, res++);
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
    printf("Изначальное число: ");
    print_bits(x);
    printf("Количество бит равных 1: %d\n", bitcount(x));
    return 0;
}