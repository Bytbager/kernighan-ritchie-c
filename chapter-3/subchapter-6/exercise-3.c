/*
Упражнение:
Напишите версию itoa с дополнительным третьим аргументом, задающим минимальную
ширину поля. При необходимости преобразованное число должно слева дополняться пробелами.
*/
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 1000
#define TEST_NUMBER 1 << 31
#define TEST_WIDTH 15

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

/* itoa: преобразование n в строку s с минимальной шириной поля width */
void itoa(int n, char s[], int width)
{
    int i, sign, need_increase = 0;
    if ((sign = n) < 0) { /* сохраняем знак */
        if (n == INT_MIN) {
            n = ~n;
            need_increase = 1;
        } else {
            n = -n;         /* делаем n положительным */
        }
    }
    i = 0;
    do
    {                          /* генерируем цифры в обратном порядке */
        s[i++] = n % 10 + '0'; /* следующая цифра */
    } while ((n /= 10) > 0); /* исключить ее */
    if (sign < 0)
        s[i++] = '-';
    if (need_increase)
        s[0]++;
    for (; i < width; i++) s[i] = ' ';
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char s[MAX_SIZE];
    itoa(TEST_NUMBER, s, TEST_WIDTH);
    printf("Изначальное число: %d\n", TEST_NUMBER);
    printf("Получившаяся строка:\n%s\n", s);
    return 0;
}