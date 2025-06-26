/*
Упражнение:
Напишите функцию strindex(s, t), которая выдает позицию самого правого вхождения
t в s или -1, если вхождения не обнаружено.
*/
#include <stdio.h>

#define MAXLINE 1000 /* максимальный размер вводимой строки */

int my_getline(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "o"; /* образец для поиска */

/* найти все строки, содержащие образец */
int main()
{
    char line[MAXLINE];
    int found = 0, index;
    printf("Шаблон для поиска: %s\n", pattern);
    while (my_getline(line, MAXLINE) > 0)
        if ((index = strindex(line, pattern)) >= 0)
        {
            printf("Последнее совпадение на позиции %d\n", index + 1);
            printf("%s", line);
            found++;
        }
    return found;
}

/* my_getline: читает строку в s, возвращает длину */
int my_getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex: вычисляет место t в s или выдает -1, если t нет в s */
int strindex(char s[], char t[])
{
    int i, j, k, pos = -1;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            pos = i;
    }
    return pos;
}