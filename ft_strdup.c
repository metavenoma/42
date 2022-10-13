/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:19:07 by rverona-          #+#    #+#             */
/*   Updated: 2022/10/13 21:15:14 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cp;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	cp = (char *)malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		cp[i] = ((char *)s)[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
