/*
В этом разделе рассказывалось о логических операторах и операторах отношения.
В качестве примера приводился цикл из функции getline из первой главы:
    for (i = 0; i < lim-1 && (с = getchar()) != EOF && с != '\n'; ++i)
        s[i] = c;

В качестве упражнения нужно написать цикл, эквивалентный этому, не пользуясь операторами
&& и ||
*/
#include <stdio.h>

#define MAX_LINE 1024

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

/* exrcise_getline: my_getline с измененным циклом */
int exercise_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1, (c = getchar()) != EOF, c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int main() {
    char line[MAX_LINE];
    my_getline(line, MAX_LINE);
    printf("line from my_getline:\n%s", line);
    exercise_getline(line, MAX_LINE);
    printf("line from exercise_getline:\n%s", line);
    return 0;
}