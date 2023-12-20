/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** Swap two integers
*/

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
