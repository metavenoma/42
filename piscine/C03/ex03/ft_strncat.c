/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 23:09:27 by rverona-          #+#    #+#             */
/*   Updated: 2022/07/26 13:40:09 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int		main(void)
{
	char a[40] = "hahahaha";
	char b[] = "huhuhuhu";
	unsigned int nb = 3;

	printf("Source: %s\nDest: %s\nnb = %d\n", b, a, nb);
	printf("Result: %s\n", ft_strncat(a, b, nb));

	return (0);
}*/
