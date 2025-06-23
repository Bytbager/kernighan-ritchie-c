/*
Упражнение:
Напишите функцию htol(s), которая преобразует последовательность
шестнадцатеричных цифр, начинающуюся с 0х или 0Х, в соответствующее целое. Шестнадцатеричными
цифрами являются символы 0…9, а…f, А…F.
*/
#include <stdio.h>

#define HEX_STR "0xf1f"

long htol(const char *src);

int main() {
    printf("hex: %s | dec: %ld\n", HEX_STR, htol(HEX_STR));
    return 0;
}

long htol(const char *src) {
    long result = 0;
    if (src != NULL) {
        if (src[0] == '0' && (src[1] == 'x' || src[1] == 'X')) {
            for (int i = 2; src[i] != '\0'; i++) {
                if (src[i] >= '0' && src[i] <= '9') {
                    result = result * 16 + (src[i] - '0');
                } else if (src[i] >= 'a' && src[i] <= 'f') {
                    result = result * 16 + (10 + src[i] - 'a');
                } else if (src[i] >= 'A' && src[i] <= 'F') {
                    result = result * 16 + (10 + src[i] - 'A');
                }
            }
        }
    }
    return result;
}
