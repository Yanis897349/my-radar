/*
** EPITECH PROJECT, 2023
** my_compute_square_root.c
** File description:
** Returns the square root
*/

static int my_compute_square_root_rec(int nb, int l_estim, int s_estim)
{
    if (s_estim < l_estim) {
        l_estim = s_estim;
        s_estim = (l_estim + nb / l_estim) / 2;
        my_compute_square_root_rec(nb, l_estim, s_estim);
    }
    if (l_estim * l_estim < nb) {
        return 0;
    }
    return l_estim;
}

int my_compute_square_root(int nb)
{
    int l_estim = 0;
    int s_estim = 0;
    int result = 0;

    if (nb <= 0) {
        return 0;
    }
    if (nb == 1) {
        return 1;
    }
    l_estim = nb / 2;
    s_estim = (l_estim + nb / l_estim) / 2;
    result = my_compute_square_root_rec(nb, l_estim, s_estim);
    return result;
}
