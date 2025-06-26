/*
Упражнение:
Напишите функцию itob(n, s, b), которая переводит целое n в строку s,
представляющую число по основанию b. В частности, itob(n, s, 16) помещает в s текст числа n в
шестнадцатеричном виде.
*/
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 1000
#define BASE 3
#define TEST_NUMBER 1 << 31

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

/* itob: преобразование n в строку s, представляющую число по основанию b */
void itob(int n, char s[], int b)
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
        int tmp = n % b;
        if (tmp < 10)
            s[i++] = tmp + '0'; /* следующая цифра */
        else
            s[i++] = tmp % 10 + 'a';
    } while ((n /= b) > 0); /* исключить ее */
    if (sign < 0)
        s[i++] = '-';
    if (need_increase) {
        for (int j = 0; j < i; j++) {
            if (b <= 10 && s[j] == '0' + b - 1) {
                s[j] = '0';
                continue;
            } else if (b > 10 && s[j] == 'a' + b - 11) {
                s[j] = '0';
                continue;
            }
            if (j == i - 1) {
                s[j + 1] = s[j];
                s[j] = '1';
                i++;
            } else {
                s[j]++;
            }
            break;
        }
    }
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char s[MAX_SIZE];
    itob(TEST_NUMBER, s, BASE);
    printf("Изначальное число: %d\n", TEST_NUMBER);
    printf("Число по основанию %d: %s\n", BASE, s);
    return 0;
}