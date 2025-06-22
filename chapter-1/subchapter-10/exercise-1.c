/*
Упражнение:
Напишите программу detab, заменяющую символы табуляции во вводимом тексте нужным
числом пробелов (до следующего "стопа" табуляции). Предполагается, что "стопы" табуляции расставлены на
фиксированном расстоянии друг от друга, скажем, через n позиций. Как лучше задавать n — в виде значения
переменной или в виде именованной константы?
*/
#include <stdio.h>

#define TAB_STOP 4 /* Значение, которое отображает количество символов между каждым стопом табуляции */
#define MAX_LEN 1000 /* Максимальная длина вводимой строки */

int my_getline(char line[], int len);
void detab(char line[], int len);

int main() {
    int len = 0;
    char line[MAX_LEN];
    while ((len = my_getline(line, MAX_LEN)) > 0) {
        detab(line, len);
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

void detab(char line[], int len) {
    char tmp[MAX_LEN * 4];
    int i, j;
    for (i = 0, j = 0; (j < MAX_LEN * 4) && (line[i] != '\n' || line[i] != '\0'); i++, j++) {
        if (line[i] == '\t') {
            int spaces_count = TAB_STOP - ((j + TAB_STOP) % TAB_STOP);
            for (int k = 0; k < spaces_count; k++) tmp[j + k] = ' ';
            j += spaces_count - 1;
        } else {
            tmp[j] = line[i];
        }
    }
    tmp[i++] = '\n';
    tmp[i++] = '\0';
    printf("%s", tmp);
}