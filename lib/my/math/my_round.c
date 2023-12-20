/*
** EPITECH PROJECT, 2023
** my_round.c
** File description:
** Rounding a float number
*/

long long my_round(double x)
{
    return (x < 0) ? (long long) (x - 0.5) : (long long) (x + 0.5);
}
