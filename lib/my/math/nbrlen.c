/*
** EPITECH PROJECT, 2023
** lib
** File description:
** nbrlen
*/

int nbr_len(long long nbr)
{
    int len = 0;

    while (nbr >= 1) {
        nbr /= 10;
        len ++;
    }
    return len;
}
