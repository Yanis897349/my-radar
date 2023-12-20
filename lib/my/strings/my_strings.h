/*
** EPITECH PROJECT, 2023
** MY_STRINGS_H_
** File description:
** Header for my strings lib
*/
#include <stddef.h>

#ifndef MY_STRINGS_H_
    #define MY_STRINGS_H_
char *my_putnbr_base(int nbr, const char *base, char *str);
char *my_putnbr_base_unsigned(unsigned int n, const char *base);
char *my_putnbr_base_int64(long int n, const char *base);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_show_str(char const *str);
int my_show_word_array(char *const *arr);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(const char *s1, const char *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_str_is_alpha(char const *str);
int my_str_is_lower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int n);
int my_strncmp(const char *s1, const char *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strndup(char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char **my_str_to_word_array(const char *str);
char *my_strupcase(char *str);
void *my_memcpy(void *dest, const void *src, size_t n);
void *my_memset(void *pointer, int value, size_t count);
char **buffer_to_array(char *buffer, char delimiter);
char *file_to_buffer(char *filepath);
int my_array_len(char **array);
#endif /* MY_STRINGS_H_ */
