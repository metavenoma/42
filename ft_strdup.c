/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:19:07 by rverona-          #+#    #+#             */
/*   Updated: 2022/09/07 22:41:20 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cp;
	int	i;

	i = 0;
	cp = (char *)malloc(((ft_strlen(s)) + 1)*sizeof(char));
	while (s[i] != '\0')
	{
		cp[i] = ((char *)s)[i];
		i++;
	}
	if (ft_strlen(s) != ft_strlen(cp))
		return (NULL);
	cp[i] = '\0';
	return (cp);
}
