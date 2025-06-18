/*
В данном упражнении нужно написать программу для подсчета пробелов, табуляций и новых строк
*/
#include <stdio.h>
/* подсчет пробелов, табуляций и строк входного потока */
int main()
{
    int c, ns, nt, nl;
    ns = nt = nl = 0;
    while ((c = getchar()) != EOF)
        switch (c) {
            case '\n': ++nl; break;
            case '\t': ++nt; break;
            case ' ': ++ns; break;
        }
    printf("Строки: %d\n", nl);
    printf("Табуляции: %d\n", nt);
    printf("Пробелы: %d\n", ns);
    return 0;
}