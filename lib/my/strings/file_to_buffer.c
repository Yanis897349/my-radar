/*
** EPITECH PROJECT, 2023
** my_string
** File description:
** file_to_buffer
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char *file_to_buffer(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat st;
    char *buffer = NULL;

    if (fd == -1)
        return NULL;
    if (stat(filepath, &st) == -1) {
        return NULL;
    }
    buffer = malloc(st.st_size + 1);
    if (buffer == NULL)
        return NULL;
    if (read(fd, buffer, st.st_size) == -1)
        return NULL;
    buffer[st.st_size] = '\0';
    close(fd);
    return buffer;
}
