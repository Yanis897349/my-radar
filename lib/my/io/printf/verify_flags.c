/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** verify flag
*/

int is_conversion_char(char current_char)
{
    static char const CONV_SPECIFIER_TAB[] = {
        'i', 'd', 'o', 'u', 'x', 'X', 'e', 'E', 'f', 'F', 'g', 'G', 'a', 'A'
        , 'c', 's', 'p'};
    int size_cs_tab = sizeof(CONV_SPECIFIER_TAB);

    for (int i = 0; i < size_cs_tab; i++) {
        if (current_char == CONV_SPECIFIER_TAB[i]) {
            return 1;
        }
    }
    return 0;
}

int jump_flags(char const *format, int indice)
{
    int nb_of_flags = 1;

    for (; format[indice] != '\0'; indice++) {
        if (is_conversion_char(format[indice])) {
            return nb_of_flags;
        }
        nb_of_flags += 1;
    }
    return 0;
}

int is_real_flag(char const *format, int indice)
{
    if (format[indice] != '%') {
        return 0;
    } else if (format[indice + 1] == '%') {
        return 0;
    }
    for (indice = indice + 1; format[indice] != '\0'; indice++) {
        if (is_conversion_char(format[indice])) {
            return 1;
        }
    }
    return 0;
}
