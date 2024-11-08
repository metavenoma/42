/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:56:51 by rverona-          #+#    #+#             */
/*   Updated: 2022/07/26 13:53:52 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	lenght;

	lenght = 0;
	while (str[lenght] != '\0')
	{
	lenght++;
	}
	return (lenght);
}
/*
int main(void)
{
	char	a[] = "Count me!";

	printf("Str: %s\n", a);
	printf("Result strlen: %lu\n", strlen(a));
	printf("Result ft_strlen: %d\n", ft_strlen(a));
}*/
