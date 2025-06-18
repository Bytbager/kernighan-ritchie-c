/*
В этом упражнении нужно сделать так, чтобы программа печатала заголовки для температур
*/
#include <stdio.h>
/* печать таблицы температур по Фаренгейту и Цельсию для
fahr = 0, 20 ... 300; вариант с плавающей точкой */
int main()
{
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;   /* нижняя граница таблицы температур */
    upper = 300; /* верхняя граница */
    step = 20;   /* шаг */
    fahr = lower;
    printf("Фаренгейты Цельсии\n"); // Печать заголовков
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%10.0f %7.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}