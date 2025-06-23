/*
Упражнение:
Напишите функцию any(s1, s2), которая возвращает либо ту позицию в s1, где стоит
первый символ, совпавший с любым из символов в s2, либо -1 (если ни один символ из s1 не совпадает с
символами из s2). (Стандартная библиотечная функция strpbrk делает то же самое, но выдает не номер
позиции символа, а указатель на символ.)
*/
#include <stdio.h>

#define TEST_STRING "arbooze"
#define TEST_SYMBOLS "uwtp"

int any(const char str[], const char symbols_to_find[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        for (int k = 0; symbols_to_find[k] != '\0'; k++) {
            if (str[i] == symbols_to_find[k]) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    char s[] = TEST_STRING;
    const int pos = any(s, TEST_SYMBOLS);
    printf("src string: %s | symbols to find: %s\n", s, TEST_SYMBOLS);
    if (pos != -1) {
        printf("first found symbol: %c\n", s[pos]);
    } else {
        printf("symbols not found\n");
    }
    return 0;
}