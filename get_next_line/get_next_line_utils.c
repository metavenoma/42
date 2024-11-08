/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:57:00 by rverona-          #+#    #+#             */
/*   Updated: 2022/11/26 23:58:37 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;

	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s1 != NULL && *s1)
	{
		res[i] = *s1;
		s1++;
		i++;
	}
	while (s2 != NULL && *s2)
	{
		res[i] = *s2;
		s2++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
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
		if (s != NULL && s[i] == (char)c)
			return (&((char *)s)[i]);
		i--;
	}
	return (NULL);
}
