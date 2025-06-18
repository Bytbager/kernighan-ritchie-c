/*
Нужно написать программу, печатающую гистограммы частот встречаемости вводимых символов
*/
#include <stdio.h>

#define IN 1  /* внутри слова */
#define OUT 0 /* вне слова */
#define SIZE 26 /* размер массива */
int main()
{
    int c;
    int lowercase[SIZE];
    int uppercase[SIZE];
    for (int i = 0; i < SIZE; i++) {
        lowercase[i] = 0;
        uppercase[i] = 0;
    }
    while ((c = getchar()) != EOF)
    {
        if (c >= 'a' && c <= 'z')
            lowercase[c - 'a']++;
        else if (c >= 'A' && c <= 'Z')
            uppercase[c - 'A']++;
    }
    printf("Символ | Количество символов\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%6c | ", i + 'a');
        for (int j = 0; j < lowercase[i]; j++)
            printf("]");
        printf("\n");
    }
    for (int i = 0; i < SIZE; i++) {
        printf("%6c | ", i + 'A');
        for (int j = 0; j < uppercase[i]; j++)
            printf("]");
        printf("\n");
    }
    return 0;
}