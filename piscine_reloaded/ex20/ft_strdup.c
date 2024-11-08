/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:08:55 by rverona-          #+#    #+#             */
/*   Updated: 2022/08/26 23:34:26 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	copy = (char *)malloc(sizeof(char) * (i + 1));
	copy[i] = '\0';
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}
