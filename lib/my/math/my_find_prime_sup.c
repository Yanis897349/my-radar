/*
** EPITECH PROJECT, 2023
** my_find_prime_sup.c
** File description:
** Returns the smallest prime number >= args
*/

#include "math/my_math.h"

int my_find_prime_sup(int nb)
{
    int result = nb;

    if (nb <= 1) {
        result = 2;
    }
    while (!my_is_prime(result)) {
        result++;
    }
    return result;
}
