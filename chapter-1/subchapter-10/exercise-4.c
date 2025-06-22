/*
Упражнение:
Напишите программу, убирающую все комментарии из любой Си-программы. Не забудьте
должным образом обработать строки символов и строковые константы. Комментарии в Си не могут быть
вложены друг в друга.
*/
#include <stdio.h>

#define MAX_LEN 1000 /* Максимальная длина вводимой строки */

int my_getline(char line[], int len);
void output_without_comments(char line[], int len);

int main() {
    int len = 0;
    char line[MAX_LEN];
    while ((len = my_getline(line, MAX_LEN)) > 0) {
        output_without_comments(line, len);
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

void output_without_comments(char line[], int len) {
    static int inside_comment = 0;
    for (int i = 0; i < len; i++) {
        if (line[i] == '/' && line[i + 1] == '/') {
            putchar('\n');
            break;
        } else if (line[i] == '/' && line[i + 1] == '*') {
            inside_comment = 1;
            ++i;
            continue;
        } else if (line[i] == '*' && line[i + 1] == '/') {
            inside_comment = 0;
            ++i;
            continue;
        }
        if (!inside_comment) {
            putchar(line[i]);
        }
    }
}