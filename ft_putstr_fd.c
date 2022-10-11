#include "libft.h"

void    ft_putstr_fd(char *str, int fd)
{
        int     s;

        s = 0;
        while (str[s] != '\0')
        {
                ft_putchar(str[s], fd);
                s++;
        }
}