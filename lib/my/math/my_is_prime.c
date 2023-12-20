/*
** EPITECH PROJECT, 2023
** my_is_prime.c
** File description:
** Returns if a number is prime
*/

#include "math/my_math.h"

int my_is_prime(int nb)
{
    int nb_squared = 0;

    if (nb <= 1) {
        return 0;
    }
    nb_squared = my_compute_square_root(nb);
    for (int i = 2; i < nb_squared; i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}
