/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:12:42 by rverona-          #+#    #+#             */
/*   Updated: 2022/09/06 20:44:41 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (c == '\0')
	{
		i++;
		return (&((char*)s)[i]);
	}
	while (i >= 0)
	{
		if (s[i] == c)
			return (&((char*)s)[i]);
		i--;
	}
	return (NULL);
}
