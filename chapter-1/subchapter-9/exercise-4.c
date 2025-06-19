/*
Нужно написать функцию reverse(string), которая будет размещать символы в строке string
в обратном порядке. Также нужно написать программу, которая выводит все строки в обратном порядке
*/
#include <stdio.h>
#define MAXLINE 1000 /* максимальный размер вводимой строки */
int my_getline(char line[], int length);
void copy(char to[], char from[]);
void reverse(char str[]);
/* печать самой длинной строки */
int main()
{
    int len;               /* длина текущей строки */
    char line[MAXLINE];    /* текущая строка */
    while ((len = my_getline(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
    }
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
/* copy: копирует из 'from' в 'to'; to достаточно большой */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
/* reverse: размещает символы в строке в обратном порядке */
void reverse(char str[]) {
    int size = 0;
    while (str[size++]);
    if (size) {
        char tmp[size];
        int i = 0, j = size - 1;
        while (str[j] == '\0' || str[j] == '\n') j--;
        for (; i < size && j > -1; i++, j--) {
            tmp[i] = str[j];
        }
        tmp[i++] = '\n';
        tmp[i++] = '\0';
        copy(str, tmp);
    }
}