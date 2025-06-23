/*
Упражнение:
Напишите версию функции squeeze(s1, s2), которая удаляет из s1 все символы,
встречающиеся в строке s2.
*/
#include <stdio.h>

#define TEST_STRING "arbooze"
#define TEST_SYMBOLS "arze"

void squeeze(char str[], const char symbols_to_remove[]) {
    int i, j;
    for (i = j = 0; str[i] != '\0'; i++) {
        int remove = 0;
        for (int k = 0; symbols_to_remove[k] != '\0'; k++) {
            if (str[i] == symbols_to_remove[k]) {
                remove = 1;
                break;
            }
        }
        if (!remove) str[j++] = str[i];
    }
    str[j] = '\0';
}

int main() {
    char s[] = TEST_STRING;
    printf("before squeeze: %s\n", s);
    squeeze(s, TEST_SYMBOLS);
    printf("after squeeze: %s\n", s);
    return 0;
}