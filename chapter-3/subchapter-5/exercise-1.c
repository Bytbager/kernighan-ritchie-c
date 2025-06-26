/*
Упражнение:
Напишите функцию expand(s1, s2), заменяющую сокращенную запись наподобие a-z в
строке s1 эквивалентной полной записью abc. . . xyz в s2. В s1 допускаются буквы (прописные и строчные) и
цифры. Следует уметь справляться с такими случаями, как a-b-c, a-z0-9 и -а-b. Считайте знак - в начале или в
конце s1 обычным символом минус.
*/
#include <stdio.h>

#define MAX_SIZE 1000
#define INSIDE 1
#define OUTSIDE 0
#define TEST_STRING "a-z0-9a-Z"

int is_digit(const char c) {
    return c >= '0' && c <= '9' ? 1 : 0;
}

int is_lower_letter(const char c) {
    return c >= 'a' && c <= 'z' ? 1 : 0;
}

int is_capital_letter(const char c) {
    return c >= 'A' && c <= 'Z' ? 1 : 0;
}

void expand(char s1[], char s2[]) {
    int i = 0, j = 0;
    int inside_word = OUTSIDE;
    if (s1[i] == '-')
        s2[j++] = s1[i++];

    for (; s1[i] != '\0'; i++) {
        const char c = s1[i];
        switch (c) {
            case '\n': case ' ': case '\t':
            {
                inside_word = OUTSIDE;
                s2[j++] = c;
                break;
            }
            case '-':
            {
                if (inside_word) {
                    const char prev = s1[i - 1], next = s1[i + 1];
                    if ((is_digit(prev) && is_digit(next)) ||
                        (is_lower_letter(prev) && is_lower_letter(next)) ||
                        (is_capital_letter(prev) && is_capital_letter(next)))
                    {
                        if (prev < next) {
                            for (int k = prev + 1; k != next; k++) s2[j++] = k;
                        } else if (prev > next) {
                            for (int k = prev - 1; k != next; k--) s2[j++] = k;
                        }
                    }
                    else
                    {
                        s2[j++] = c;
                    }
                }
                break;
            }
            default:
            {
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                    inside_word = INSIDE;
                }
                s2[j++] = c;
                break;
            }
        }
    }
    s2[j++] = '\0';
}

int main() {
    char s1[MAX_SIZE] = TEST_STRING, s2[MAX_SIZE * 2];
    printf("Изначальная строка: %s\n", s1);
    expand(s1, s2);
    printf("Строка после expand: %s\n", s2);
    return 0;
}