/*
Нужно переписать программу преобразования температур, выделив само преобразование в
отдельную функцию
*/
#include <stdio.h>
/* печать таблицы температур по Фаренгейту и Цельсию для
fahr = 0, 20 ... 300; вариант с плавающей точкой */
float fahr_to_celsius(float fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}

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
        celsius = fahr_to_celsius(fahr);
        printf("%10.0f %7.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}