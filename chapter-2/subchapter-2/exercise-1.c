/*
Упражнение:
Напишите программу, которая будет выдавать диапазоны значений типов char, short,
int и long, описанных как signed и как unsigned, с помощью печати соответствующих значений из
стандартных заголовочных файлов и путем прямого вычисления. Определите диапазоны чисел с плавающей
точкой различных типов. Вычислить эти диапазоны сложнее.
*/
#include <stdio.h>
#include <limits.h>
#include <float.h>

#define UNSIGNED_MIN 0 /* Минимальное значение любого беззнакового типа */
#define BITS 8 /* Количество бит в одном байте */

int main() {
    printf("Диапазоны значений из limits.h:\n");
    printf("signed char: от %d до %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char: от %u до %u\n", UNSIGNED_MIN, UCHAR_MAX);
    printf("signed short: от %d до %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: от %u до %u\n", UNSIGNED_MIN, USHRT_MAX);
    printf("signed int: от %d до %d\n", INT_MIN, INT_MAX);
    printf("unsigned int: от %u до %u\n", UNSIGNED_MIN, UINT_MAX);
    printf("signed long: от %ld до %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: от %u до %lu\n", UNSIGNED_MIN, ULONG_MAX);
    printf("Диапазоны значений путём прямых вычислений:\n");
    signed char scmin = 1 << (sizeof(char) * BITS - 1), scmax = 0;
    for (int i = sizeof(char) * BITS - 1; i != 0; i--) {
        scmax <<= 1;
        scmax |= 1;
    }
    printf("signed char: от %d до %d\n", scmin, scmax);
    unsigned char ucmax = 0;
    for (int i = sizeof(char) * BITS; i != 0; i--) {
        ucmax <<= 1;
        ucmax |= 1;
    }
    printf("unsigned char: от %u до %u\n", UNSIGNED_MIN, ucmax);

    signed short ssmin = 1 << (sizeof(short) * BITS - 1), ssmax = 0;
    for (int i = sizeof(short) * BITS - 1; i != 0; i--) {
        ssmax <<= 1;
        ssmax |= 1;
    }
    printf("signed short: от %d до %d\n", ssmin, ssmax);
    unsigned short usmax = 0;
    for (int i = sizeof(short) * BITS; i != 0; i--) {
        usmax <<= 1;
        usmax |= 1;
    }
    printf("unsigned short: от %u до %u\n", UNSIGNED_MIN, usmax);

    signed int simin = 1 << (sizeof(int) * BITS - 1), simax = 0;
    for (int i = sizeof(int) * BITS - 1; i != 0; i--) {
        simax <<= 1;
        simax |= 1;
    }
    printf("signed int: от %d до %d\n", simin, simax);
    unsigned int uimax = 0;
    for (int i = sizeof(int) * BITS; i != 0; i--) {
        uimax <<= 1;
        uimax |= 1;
    }
    printf("unsigned int: от %u до %u\n", UNSIGNED_MIN, uimax);

    signed long slmin = 1L << (sizeof(signed long) * BITS - 1), slmax = 0;
    for (int i = sizeof(long) * BITS - 1; i != 0; i--) {
        slmax <<= 1;
        slmax |= 1;
    }
    printf("signed long: от %ld до %ld\n", slmin, slmax);
    unsigned long ulmax = 0;
    for (int i = sizeof(long) * BITS; i != 0; i--) {
        ulmax <<= 1;
        ulmax |= 1;
    }
    printf("unsigned long: от %u до %lu\n", UNSIGNED_MIN, ulmax);

    printf("Диапазон значений для float и double из float.h\n");
    printf("float: от %f до %f\n", FLT_MIN, FLT_MAX);
    printf("double: от %f до %f\n", DBL_MIN, DBL_MAX);
    printf("Диапазон значений для float и double путём прямых вычислений\n");
    float f = FLT_MAX;
    char *p = (char *)&f + sizeof(float) - 1;
    *p = *p | 1 << (sizeof(char) * BITS - 1);
    printf("float: от %f до %f\n", f, FLT_MAX);
    double d = DBL_MAX;
    p = (char *)&d + sizeof(double) - 1;
    *p = *p | 1 << (sizeof(char) * BITS - 1);
    printf("double: от %f до %f\n", d, DBL_MAX);

    return 0;
}
