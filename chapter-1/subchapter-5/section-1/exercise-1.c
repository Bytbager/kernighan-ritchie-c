/*
Нужно написать программу, которая заставит нас убедиться в том, что
выражение getchar() != EOF получает значение 0 или 1.
*/
#include <stdio.h>
int main()
{
    printf("(getchar() != EOF) = %d\n", getchar() != EOF);
    return 0;
}