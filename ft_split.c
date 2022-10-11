#include "libft.h"

static size_t   ft_counter(char const *s, chart c)
{
    size_t  counter;
    
    if (!*s)
        return (0);
    counter = 0;
    while (*s)
    {
        while (*s == c)
            s++;
        if (*s)
            count++;
        while (*s != c && *s)
            s++;
    }
    return (counter);
}

char    **ft_split(char const *s, char c)
{
    char    **res;
    size_t  sub_len;

    res = (char **)malloc((ft_counter(s, c) + 1) * sizeof(char *));
    if (!s || !res)
        return (0);
}