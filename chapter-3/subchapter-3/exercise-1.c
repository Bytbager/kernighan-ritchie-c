/*
Упражнение:
В нашей программе бинарного поиска внутри цикла осуществляются две проверки, хотя
могла быть только одна (при увеличении числа проверок вне цикла). Напишите программу, предусмотрев в
ней одну проверку внутри цикла. Оцените разницу во времени выполнения.

Для проверки времени выполнения использовал утилиту time
В моем случае программа из упражнения всегда проигрывает стартовой программе
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX_SIZE 50000000
#define MAX_NUMBER 1000000
#define SEARCH_NUMBER 120

/* binsearch: найти х в v[0] <= v[1] <= … <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (x > v[mid])
            low = mid + 1;
        else
            high = mid;
    }
    return x == v[low] ? low : -1;
}

int compare(const void *a, const void *b) {
    int int_a = *((int *)a);
    int int_b = *((int *)b);
    if (int_a == int_b) return 0;
    else if (int_a < int_b) return -1;
    else return 1;
}

int main() {
    int *v = malloc(sizeof(int) * ARRAY_MAX_SIZE);
    srand(time(NULL));
    for (int i = 0; i < ARRAY_MAX_SIZE; i++) {
        v[i] = rand() % MAX_NUMBER;
    }
    qsort(v, ARRAY_MAX_SIZE, sizeof(int), compare);
    int res = 0;
    if ((res = binsearch(SEARCH_NUMBER, v, ARRAY_MAX_SIZE)) == -1) {
        printf("Число %d не найдено\n", SEARCH_NUMBER);
    } else {
        printf("Число %d найдено на позиции %d. v[%d] = %d\n", SEARCH_NUMBER, res, res, v[res]);
    }
    return 0;
}