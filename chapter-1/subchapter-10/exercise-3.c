/*
Упражнение:
Напишите программу, печатающую символы входного потока так, чтобы строки текста не
выходили правее n-й позиции. Это значит, что каждая строка, длина которой превышает n, должна печататься
с переносом на следующие строки. Место переноса следует "искать" после последнего символа, отличного от
символа-разделителя, расположенного левее n-й позиции. Позаботьтесь о том, чтобы ваша программа вела
себя разумно в случае очень длинных строк, а также когда до n-й позиции не встречается ни одного символа
пробела или табуляции
*/
#include <stdio.h>

#define MAX_OUTPUT_LEN 50 /* Длина, после которой символы строки должны переводиться на новую строку */
#define MAX_LEN 1000 /* Максимальная длина вводимой строки */

int my_getline(char line[], int len);
void format_output(char line[], int len);

int main() {
    int len = 0;
    char line[MAX_LEN];
    while ((len = my_getline(line, MAX_LEN)) > 0) {
        format_output(line, len);
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

void format_output(char line[], int len) {
    int last_white = -1;
    int continuation = -1;
    char tmp[MAX_OUTPUT_LEN + 1];
    for (int i = 0, j = 1, tmp_it = 0; i < len; i++, j++, tmp_it++) {
        if (line[i] == ' ' || line[i] == '\t'){
            last_white = tmp_it;
            continuation = i;
        } else if (line[i] == '\n') {
            tmp[tmp_it] = 0;
            printf("%s\n", tmp);
            break;
        }
        tmp[tmp_it] = line[i];
        if (MAX_OUTPUT_LEN - j == 1) {
            j = 0;
            if (last_white != -1) {
                tmp[last_white++] = '\n';
                tmp[last_white] = '\0';
                printf("%s", tmp);
                for (int a = 0; a < last_white; a++) tmp[a] = 0;
                last_white = -1;
                if (continuation != -1) {
                    i = continuation;
                    continuation = -1;
                }
            } else {
                tmp[++tmp_it] = '\0';
                printf("%s-\n", tmp);
            }
            tmp_it = -1;
        }
    }
}