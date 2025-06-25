/*
Упражнение:
Напишите функцию escape(s, t), которая при копировании текста из t в s преобразует
такие символы, как новая строка и табуляция в "видимые последовательности символов" (вроде \n и \t).
Используйте инструкцию switch. Напишите функцию, выполняющую обратное преобразование эскейп-
последовательностей в настоящие символы.
*/
#include <stdio.h>

#define MAX_SIZE 100 /* Максимальный размер массива */
#define TEST_STRING "Hello\tworld\n"

void escape(char dst[], char src[]) {
    int i, j;
    for (i = j = 0; src[i] != '\0'; i++) {
        switch (src[i]) {
            case '\t':
            {
                dst[j++] = '\\';
                dst[j++] = 't';
                break;
            }
            case '\n':
            {
                dst[j++] = '\\';
                dst[j++] = 'n';
                break;
            }
            default:
            {
                dst[j++] = src[i];
                break;
            }
        }
    }
}

void reverse_escape(char dst[], char src[]) {
    int i, j;
    for (i = j = 0; src[i] != '\0'; i++) {
        switch (src[i]) {
            case '\\':
            {
                switch (src[i + 1]) {
                    case 'n':
                    {
                        dst[j++] = '\n';
                        i++;
                        break;
                    }
                    case 't':
                    {
                        dst[j++] = '\t';
                        i++;
                        break;
                    }
                }
                break;
            }
            default:
            {
                dst[j++] = src[i];
                break;
            }
        }
    }
}

int main() {
    char dst[MAX_SIZE * 2], src[MAX_SIZE] = TEST_STRING;
    printf("Изначальная строка: %s\n", src);
    escape(dst, src);
    printf("Строка после ecape: %s\n", dst);
    char new[MAX_SIZE * 2];
    reverse_escape(new, dst);
    printf("Та же строка после reverse_escape: %s\n", new);
    return 0;
}