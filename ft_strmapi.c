#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
        char                    *str;
        unsigned int    i;

        str = (char *)malloc(ft_strlen(s) + 1);
        i = 0;
        while (s[i])
        {
                str[i] = f(i, s[i]);
                i++;
        }
        str[i] = '\0';
        if (!str)
                return (NULL);
        return (str);
}