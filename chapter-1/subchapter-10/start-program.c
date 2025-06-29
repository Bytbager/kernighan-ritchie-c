/*
В данной программе приведены примеры использования глобальных переменных
Она не понадобится для выплнения упражнений из этого раздела
*/

#include <stdio.h>
#define MAXLINE 1000   /* максимальный размер вводимой строки */
int max;               /* длина максимальной из просмотренных строк */
char line[MAXLINE];    /* текущая строка */
char longest[MAXLINE]; /* самая длинная строка */
int my_getline(void);
void copy(void);
/* печать самой длинной строки; специализированная версия */
int main()
{
    int len;
    extern int max;
    extern char longest[];
    max = 0;
    while ((len = my_getline()) > 0)
        if (len > max)
        {
            max = len;
            copy();
        }
    if (max > 0) /* была хотя бы одна строка */
        printf("%s", longest);
    return 0;
}
/* my_getline: специализированная версия */
int my_getline(void)
{
    int c, i;
    extern char line[];
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
/* copy: специализированная версия */
void copy(void)
{
    int i;
    extern char line[], longest[];
    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}