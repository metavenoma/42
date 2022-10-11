#include "libft.h"

void    ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int    i;

    i = 0;
    while (i < ft_strlen(s))
    {
        f(i, &s[i]);
        i++;
    }
}