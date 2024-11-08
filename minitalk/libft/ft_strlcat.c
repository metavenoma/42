/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:25:36 by rverona-          #+#    #+#             */
/*   Updated: 2022/10/13 23:51:23 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = ft_strlen(dst);
	if (size > i)
	{
		res = ft_strlen(dst) + ft_strlen(src);
		j = 0;
		while (src[j] != '\0' && (i + 1) < size)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	else
		res = ft_strlen(src) + size;
	return (res);
}
