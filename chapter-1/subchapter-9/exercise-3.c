/*
Нужно написать программу, которая будет в каждой вводимой строке заменять стоящие подряд
символы пробелов и табуляций на один пробел и удалять пустые строки
*/
#include <stdio.h>
#define MAXLINE 1000 /* максимальный размер вводимой строки */
int my_getline(char line[], int length);
void copy(char to[], char from[]);
void print_string(char str[], int len);
/* печать самой длинной строки */
int main()
{
    int len;               /* длина текущей строки */
    char line[MAXLINE];    /* текущая строка */
    while ((len = my_getline(line, MAXLINE)) > 0)
        print_string(line, len);
    return 0;
}
/*
print_string: выводит строку, если она не пустая, также заменяет, стоящие
подряд пробелы и табуляции на один символ
*/
void print_string(char str[], int len) {
    if (len > 1) {
        int isspase = 0;
        int istab = 0;
        for (int i = 0; i < len; i++) {
            if (str[i] == ' ' && !isspase) {
                putchar(str[i]);
                isspase = 1;
            } else if (str[i] != ' ' && isspase) {
                putchar(str[i]);
                isspase = 0;
            } else if (str[i] == '\t' && !istab) {
                putchar(str[i]);
                istab = 1;
            } else if (str[i] != '\t' && istab) {
                putchar(str[i]);
                istab = 0;
            } else if (!isspase && !istab) {
                putchar(str[i]);
            }
        }
    }
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
/* copy: копирует из 'from' в 'to'; to достаточно большой */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}