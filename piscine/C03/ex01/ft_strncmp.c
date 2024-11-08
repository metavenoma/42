/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:52:59 by rverona-          #+#    #+#             */
/*   Updated: 2022/07/26 18:36:49 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (i < n - 1)
		&& (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}
/*
int main(void)
{
	char teste[] = "This is a test string";
	char teste2[] = "This is not a test string";
	char *teste3;
	char *teste4;
	unsigned int teste5;
	teste3 = teste;
	teste4 = teste2;
	teste5 = 8;

	
	printf("s1: %s\ns2: %s\nn: %d\n", teste3, teste4, teste5);
	printf("Result strncmp: %d\n", strncmp(teste3, teste4, teste5));
	printf("Result ft_strncmp: %d\n", ft_strncmp(teste3, teste4, teste5));
	return (0);
}*/
