#include <stddef.h>
#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int	i;

	res = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	i = 0;
	while (*s1)
	{
		res[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		res[i] = *s2;
		s2++;
		i++;
	}
	res[i] = '\0';
	if (!res)
		return (NULL);
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i--;
	}
	return (NULL);
}
