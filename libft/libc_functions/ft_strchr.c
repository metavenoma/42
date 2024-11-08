/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:30:18 by rverona-          #+#    #+#             */
/*   Updated: 2022/10/13 20:48:20 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((*s != (char)c) && (*s != '\0'))
		s++;
	if (*s == (char)c)
		return ((char *)s);
	if (c == '\0')
	{
		s++;
		return ((char *)s);
	}
	return (NULL);
}
