/*
** EPITECH PROJECT, 2023
** my_isalpha.c
** File description:
** Returns if a character is alpha
*/

int my_isalpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    else if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}
