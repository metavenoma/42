/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:28:42 by rverona-          #+#    #+#             */
/*   Updated: 2022/07/26 13:36:06 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0' || *s2 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/*
int	main(void)
{
	char	a[] = "This is a test string";
	char	b[] = "This is not a test string";

	printf("s1: %s\ns2: %s\n", a, b);
	printf("result strcmp: %d\n", strcmp(a, b));
	printf("result ft_strcmp: %d\n", ft_strcmp(a, b));
}*/
