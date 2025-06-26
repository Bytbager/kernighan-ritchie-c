#include <stdio.h>

#define MAXLINE 1000 /* максимальный размер вводимой строки */
#define TEST_LINE "Ah Love! could you and I with Fate conspire\n" \
                  "To grasp this sorry Scheme of Things entire,\n" \
                  "Would not we shatter it to bits — and then\n" \
                  "Re-mould it nearer to the Heart's Desire!" \

int my_getline(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould"; /* образец для поиска */

/* найти все строки, содержащие образец */
int main()
{
    char line[MAXLINE] = TEST_LINE;
    int found = 0;
    while (my_getline(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0)
        {
            printf("%s", line);
            found++;
        }
    return found;
}

/* my_getline: читает строку в s, возвращает длину */
int my_getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex: вычисляет место t в s или выдает -1, если t нет в s */
int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}