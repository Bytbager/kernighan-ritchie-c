/*
Нужно написать программу, которая печатает содержимое своего ввода, помещая по одному
слову на каждой строке
*/
#include <stdio.h>

#define IN 1  /* внутри слова */
#define OUT 0 /* вне слова */
int main()
{
    int c, state;
    state = OUT;
    while ((c = getchar()) != EOF)
    {
        if ((c == ' ' || c == '\n' || c == '\t') && state == IN)
        {
            state = OUT;
            putchar('\n');
        }
        else if (state == IN)
        {
            putchar(c);
        }
        else if (state == OUT)
        {
            putchar(c);
            state = IN;
        }
    }
    return 0;
}