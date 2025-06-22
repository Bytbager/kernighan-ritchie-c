/*
Упражнение:
Напишите программу, проверяющую Си-программы на элементарные синтаксические
ошибки вроде несбалансированности скобок всех видов. Не забудьте о кавычках (одиночных и двойных),
эскейп-последовательностях (\...) и комментариях. (Это сложная программа, если писать ее для общего
случая.)
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000 /* Максимальная длина вводимой строки */
#define STACK_BOTTOM NULL

typedef struct token_info {
    char symbol;
    unsigned line_number;
    unsigned symbol_number;
} token_info;

typedef struct my_stack {
    void *value;
    struct my_stack *next;
} my_stack;

my_stack *my_stack_push(my_stack *top, void *value) {
    my_stack *new = malloc(sizeof(my_stack));
    if (new != NULL) {
        new->value = value;
        new->next = top;
    }
    return new;
}

void *my_stack_pop(my_stack **top) {
    void *res = NULL;
    if (top != STACK_BOTTOM) {
        my_stack *tmp = *top;
        *top = (*top)->next;
        res = tmp->value;
        free(tmp);
    }
    return res;
}

my_stack *opening;

int inside_comment = 0; /* Флаг, говорящий о том, что мы в комментарии */
int inside_single_quotes = 0; /* Флаг, говорящий о том, что мы в одинарных кавычках */
int inside_double_quotes = 0; /* Флаг, говорящий о том, что мы в двойных кавычках */
int inside_escape_sequence = 0; /* Флаг, говорящий о том, что мы в эскейп последовательности */

int my_getline(char line[], int len);
void syntax_check(char line[], int len);
void memory_clean();

int main() {
    atexit(memory_clean);
    opening = malloc(sizeof(my_stack));
    opening->value = NULL;
    opening->next = STACK_BOTTOM;
    int len = 0;
    char line[MAX_LEN];
    while ((len = my_getline(line, MAX_LEN)) > 0) {
        syntax_check(line, len);
    }
    while (opening->next != STACK_BOTTOM) {
        token_info *token = (token_info *)opening->value;
        printf("syntax error: unexpected token \'%c\'. line: %d. symbol: %d\n", token->symbol, token->line_number, token->symbol_number);
        free(my_stack_pop(&opening));
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

/* test comment 1 )]} {[("'*/
// test comment 2 )]} {[("'

void syntax_check(char line[], int len) {
    static int line_number = 1;
    for (int i = 0; i < len; i++) {
        switch (line[i]) {
            case '(':
            {
                if (!inside_comment && !inside_double_quotes && !inside_single_quotes) {
                    token_info *token = malloc(sizeof(token_info));
                    token->symbol = line[i];
                    token->line_number = line_number;
                    token->symbol_number = i + 1;
                    opening = my_stack_push(opening, token);
                    continue;
                }
                break;
            }
            case ')':
            {
                if (!inside_comment && !inside_double_quotes && !inside_single_quotes) {
                    token_info *token = opening->value;
                    if (token->symbol == '(')
                    {
                        free(my_stack_pop(&opening));
                    }
                    else
                    {
                        printf("syntax error: unexpected token \'%c\'. line: %d. symbol: %d\n", line[i], line_number, i + 1);
                        exit(EXIT_FAILURE);
                    }
                }
                break;
            }
            case '[':
            {
                if (!inside_comment && !inside_double_quotes && !inside_single_quotes) {
                    token_info *token = malloc(sizeof(token_info));
                    token->symbol = line[i];
                    token->line_number = line_number;
                    token->symbol_number = i + 1;
                    opening = my_stack_push(opening, token);
                    continue;
                }
                break;
            }
            case ']':
            {
                if (!inside_comment && !inside_double_quotes && !inside_single_quotes) {
                    token_info *token = opening->value;
                    if (token->symbol == '[')
                    {
                        free(my_stack_pop(&opening));
                    }
                    else
                    {
                        printf("syntax error: unexpected token \'%c\'. line: %d. symbol: %d\n", line[i], line_number, i + 1);
                        exit(EXIT_FAILURE);
                    }
                }
                break;
            }
            case '{':
            {
                if (!inside_comment && !inside_double_quotes && !inside_single_quotes) {
                    token_info *token = malloc(sizeof(token_info));
                    token->symbol = line[i];
                    token->line_number = line_number;
                    token->symbol_number = i + 1;
                    opening = my_stack_push(opening, token);
                    continue;
                }
                break;
            }
            case '}':
            {
                if (!inside_comment && !inside_double_quotes && !inside_single_quotes) {
                    token_info *token = opening->value;
                    if (token->symbol == '{')
                    {
                        free(my_stack_pop(&opening));
                    }
                    else
                    {
                        printf("syntax error: unexpected token \'%c\'. line: %d. symbol: %d\n", line[i], line_number, i + 1);
                        exit(EXIT_FAILURE);
                    }
                }
                break;
            }
            case '/':
            {
                if (!inside_single_quotes && !inside_double_quotes) {
                    if (line[i + 1] == '/') {
                        line_number++;
                        return;
                    } else if (line[i + 1] == '*') {
                        inside_comment = 1;
                        ++i;
                        continue;
                    }
                }
                break;
            }
            case '*':
            {
                if (inside_comment && line[i + 1] == '/') {
                    inside_comment = 0;
                    ++i;
                    continue;
                }
                break;
            }
            case '\'':
            {
                if (!inside_comment && !inside_double_quotes) {
                    inside_single_quotes = !inside_single_quotes;
                    continue;
                }
                break;
            }
            case '"':
            {
                if (!inside_comment && !inside_single_quotes) {
                    inside_double_quotes = !inside_double_quotes;
                    continue;
                }
                break;
            }
            case '\\':
            {
                if (inside_single_quotes || inside_double_quotes) {
                    switch (line[i + 1]) {
                        case '\\':
                        case '\'':
                        case '"':
                        case '0':
                        case 't':
                        case 'n':
                        case 'b':
                        {
                            ++i;
                            continue;
                        }
                        default:
                        {
                            printf("syntax error: unhandled escape sequence \"%c%c\"\n", line[i], line[i + 1]);
                            continue;
                        }
                    }
                }
                break;
            }
            default: continue;
        }
    }
    line_number++;
}

void memory_clean() {
    while (opening->next != STACK_BOTTOM) {
        free(my_stack_pop(&opening));
    }
    free(opening->value);
    free(opening);
}