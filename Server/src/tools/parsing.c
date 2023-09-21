/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** parsing
*/

#include "server.h"

int count_words(const char *str, char separator)
{
    int nb_words = 0;

    if (!str)
        return -1;
    for (int idx = 0; str[idx] != '\0'; idx += 1)
        if (str[idx] == separator)
            nb_words += 1;
    return nb_words + 1;
}

int *init_col_sizes(int nb_lines)
{
    int *col_sizes = NULL;

    if (!(col_sizes = malloc(sizeof(int) * (nb_lines + 1))))
        return NULL;
    for (int idx = 0; idx < nb_lines + 1; idx += 1)
        col_sizes[idx] = 0;
    return col_sizes;
}

int *get_words_sizes(const char *str, char separator)
{
    int *col_sizes = NULL;
    int line = 0;
    int nb_lines = 0;

    if (!str)
        return NULL;
    for (int idx = 0; str[idx] != '\0'; idx += 1)
        if (str[idx] == separator)
            nb_lines += 1;
    if (!(col_sizes = init_col_sizes(nb_lines)))
        return NULL;
    for (int idx = 0; str[idx] != '\0'; idx += 1) {
        if (str[idx] != separator)
            col_sizes[line] += 1;
        else
            line += 1;
    }
    return col_sizes;
}

char **free_all_words(int idx, char **words, int *words_len)
{
    for (int i = 0; i < idx; i += 1)
        free(words[idx]);
    free(words);
    free(words_len);
    return NULL;
}

char **parse_args(const char *str)
{
    int word_count = count_words(str, ' ');
    int *words_len = get_words_sizes(str, ' ');
    char **words = NULL;
    const char *str_ptr = str;

    if (!str)
        return NULL;
    if (!(words = malloc(sizeof(char *) * (word_count + 1)))) {
        free(words_len);
        return NULL;
    }
    for (int idx = 0; idx < word_count; idx += 1) {
        if (!(words[idx] = strndup(str_ptr, words_len[idx])))
            return free_all_words(idx, words, words_len);
        str_ptr += words_len[idx] + 1;
    }
    words[word_count] = NULL;
    free(words_len);
    return words;
}
