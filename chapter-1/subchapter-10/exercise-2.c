/*
Упражнение:
Напишите программу entab, заменяющую строки из пробелов минимальным числом
табуляций и пробелов таким образом, чтобы вид напечатанного текста не изменился. Используйте те же
"стопы" табуляции, что и в detab. В случае, когда для выхода на очередной "стоп" годится один пробел, что
лучше — пробел или табуляция?
*/
#include <stdio.h>

#define TAB_STOP 8 /* Значение, которое отображает количество символов между каждым стопом табуляции */
#define MAX_LEN 1000 /* Максимальная длина вводимой строки */

int my_getline(char line[], int len);
void entab(char line[], int len);

int main() {
    int len = 0;
    char line[MAX_LEN];
    while ((len = my_getline(line, MAX_LEN)) > 0) {
        entab(line, len);
    }
}

/* my_getline: читает строку в s, возвращает длину */
int my_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void entab(char line[], int len) {
    char tmp[MAX_LEN];
    int spaces_count, tabs_count, isspace, was_symbols;
    spaces_count = tabs_count = isspace = was_symbols = 0;
    int j = 0;
    for (int i = 0; i < len && j < MAX_LEN; i++) {
        if (line[i] == ' ' && !was_symbols) {
            for (int k = 0; k < TAB_STOP - (i % TAB_STOP); k++) {
                if (line[i + k] != ' ') {
                    was_symbols = 1;
                    break;
                }
            }
            if (!was_symbols) {
                tmp[j++] = '\t';
                i += TAB_STOP - (i % TAB_STOP) - 1;
                continue;
            }
        }
        tmp[j++] = line[i];
        if (line[i] != ' ') was_symbols = 0;
    }
    tmp[j++] = '\0';
    printf("%s", tmp);
}