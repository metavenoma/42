/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:51:22 by rverona-          #+#    #+#             */
/*   Updated: 2022/07/27 12:05:13 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i < 46341)
	{
		if (i * i == nb)
			return (i);
	i++;
	}
	return (0);
}
/*
int	ft_atoi(char *str)
{
	int	negative;
	int	result;
	int	i;

	negative = 1;
	i = 0;
	while (str[i] <= 32 || str[i] == 127)
		i++;
	while (str[i] == '+' || str[i] == '-' )
	{
		if (str[i] == '-')
			negative *= -1;
	i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += (str[i] - 48);
		i++;
	}
	return (result * negative);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	printf("Result: %d\n", ft_sqrt(ft_atoi(argv[1])));
}*/
