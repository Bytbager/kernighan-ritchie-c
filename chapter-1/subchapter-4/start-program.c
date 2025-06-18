/*
В данной подглаве нет упражений, в ней было описано, как работает директива #define
*/
#include <stdio.h>

#define LOWER 0 /* Нижняя граница таблицы */
#define UPPER 300 /* Верхняя граница таблицы */
#define STEP 20 /* Размер шага */

/* печать таблицы температур по Фаренгейту и Цельсию */
int main()
{
    for (int fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    return 0;
}