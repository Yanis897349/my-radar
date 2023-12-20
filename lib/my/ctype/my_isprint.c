/*
** EPITECH PROJECT, 2023
** my_isprint.c
** File description:
** Check if a character is printable
*/

int my_isprint(char c)
{
    return (c >= 32 && c <= 126);
}
