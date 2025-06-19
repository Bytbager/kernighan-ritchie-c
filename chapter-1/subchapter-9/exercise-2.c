/*
Нужно написать программу, которая будет выводить все строки, длина которых
более 80 символов
*/
#include <stdio.h>
#define LENGTH_TO_OUTPUT 80 /* если длина вводимой строки выше этого значения, то нужно ее вывести */
#define MAXLINE 1000 /* максимальный размер вводимой строки */
int my_getline(char line[], int length);
/* печать самой длинной строки */
int main()
{
    int len;               /* длина текущей строки */
    char line[MAXLINE];    /* текущая строка */
    while ((len = my_getline(line, MAXLINE)) > 0)
        if (len > LENGTH_TO_OUTPUT)
            printf("%s", line);
    return 0;
}
/* my_getline: читает строку в s, возвращает длину */
int my_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}