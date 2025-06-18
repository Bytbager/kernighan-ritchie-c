/*
Нужно написать программу, печатающую гистограммы длин вводимых слов
*/
#include <stdio.h>

#define IN 1  /* внутри слова */
#define OUT 0 /* вне слова */
#define SIZE 30 /* размер массива */
int main()
{
    int c, state, length = 0;
    int array[SIZE];
    for (int i = 0; i < SIZE; i++)
        array[i] = 0;
    state = OUT;
    while ((c = getchar()) != EOF)
    {
        if ((c == ' ' || c == '\n' || c == '\t') && state == IN)
        {
            state = OUT;
            if (length < SIZE)
                ++array[length];
            length = 0;
        }
        else if (state == IN)
        {
            ++length;
        }
        else if (state == OUT)
        {
            state = IN;
            ++length;
        }
    }
    printf("Длина слова | Количество слов с такой длиной\n");
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%11d | ", i);
        for (int j = 0; j < array[i]; j++)
            printf("]");
        printf("\n");
    }
    return 0;
}