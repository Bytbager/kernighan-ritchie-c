/*
В этом упражнении нужно сделать так, чтобы программа печатала таблицу
соответствия температур по Цельсию температурам по Фаренгейту
*/
#include <stdio.h>
int main()
{
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;   /* нижняя граница таблицы температур */
    upper = 300; /* верхняя граница */
    step = 20;   /* шаг */
    fahr = lower;
    printf("Цельсии Фаренгейты\n"); // Печать заголовков
    while (celsius <= upper)
    {
        fahr = celsius * (9.0 / 5.0) + 32.0;
        printf("%7.0f %10.1f\n", celsius, fahr);
        celsius += step;
    }
    return 0;
}