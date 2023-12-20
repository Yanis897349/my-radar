/*
** EPITECH PROJECT, 2023
** my_pow10.c
** File description:
** Power of 10
*/

/*
** Basic implementation, requires overflow checking, etc...
*/
double my_pow10(int p)
{
    double result = 1;

    while (p > 0) {
        result = result * 10;
        p--;
    }
    return result;
}
