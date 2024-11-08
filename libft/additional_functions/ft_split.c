/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:51:31 by rverona-          #+#    #+#             */
/*   Updated: 2022/10/13 22:48:18 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_counter(char const *s, char c)
{
	size_t	counter;

	if (!*s)
		return (0);
	counter = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			counter++;
		while (*s != c && *s)
			s++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	sub_len;
	int		i;

	res = (char **)malloc((ft_counter(s, c) + 1) * sizeof(char *));
	if (!s || !res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				sub_len = ft_strlen(s);
			else
				sub_len = ft_strchr(s, c) - s;
			res[i++] = ft_substr(s, 0, sub_len);
			s += sub_len;
		}
	}
	res[i] = NULL;
	return (res);
}
