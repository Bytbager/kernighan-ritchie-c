#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

/* reverse: переворачивает строку s (результат в s) */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa: преобразование n в строку s */
void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0) /* сохраняем знак */
        n = -n;         /* делаем n положительным */
    i = 0;
    do
    {                          /* генерируем цифры в обратном порядке */
        s[i++] = n % 10 + '0'; /* следующая цифра */
    } while ((n /= 10) > 0); /* исключить ее */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main()
{
    int i = 1 << 30;
    char s[MAX_SIZE];
    itoa(i, s);
    printf("Изначальное число: %d\n", i);
    printf("Получившаяся строка: %s\n", s);
    return 0;
}