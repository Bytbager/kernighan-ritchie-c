/*
В данном упражнении нужно написать программу, копирующую символы ввода в
выходной поток и заменяющую стоящие подряд пробелы на один пробел
*/
#include <stdio.h>
/* подсчет пробелов, табуляций и строк входного потока */
int main()
{
    int c, isspace = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' && isspace == 0) {
            isspace = 1;
            putchar(c);
        } else if (c != ' ' && isspace == 1) {
            isspace = 0;
        }
        if (c != ' ')
            putchar(c);
    }
    return 0;
}