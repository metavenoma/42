/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 22:35:10 by rverona-          #+#    #+#             */
/*   Updated: 2022/10/13 23:02:43 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if ((size_t)start > ft_strlen(s))
	{
		res = malloc(sizeof(char) * 1);
		res[0] = '\0';
		return (res);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (len > ft_strlen(s + start))
		len = len - start;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, (s + start), len + 1);
	return (res);
}
