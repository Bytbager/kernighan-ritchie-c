/*
Упражнение:
Напишите функцию lower, которая переводит большие буквы в малые, используя
условное выражение (а не конструкцию if-else).
*/
#include <stdio.h>

#define TEST_STRING "ARBOOZE"

int lower(int letter) {
    return letter >= 'A' ? (letter <= 'Z' ? (letter + 'a' - 'A') : letter) : letter;
}

int main() {
    char str[] = TEST_STRING;
    printf("Изначальная строка: %s\n", str);
    for (int i = 0; str[i] != '\0'; i++) str[i] = lower(str[i]);
    printf("Строка после lower: %s\n", str);
    return 0;
}