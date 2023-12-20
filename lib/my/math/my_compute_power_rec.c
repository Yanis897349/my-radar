/*
** EPITECH PROJECT, 2023
** my_compute_power_rec.c
** File description:
** Recursive function that returns n^p
*/

#include <limits.h>

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    }
    result = my_compute_power_rec(nb, p - 1);
    if (result == 0 || (nb > 0 && result > INT_MAX / nb) ||
            (nb < 0 && result > INT_MIN / nb)) {
        return 0;
    }
    return result * nb;
}
