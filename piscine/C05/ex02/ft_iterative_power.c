/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:39:03 by rverona-          #+#    #+#             */
/*   Updated: 2022/07/27 12:04:47 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	aux;
	int	counter;

	aux = nb;
	counter = 0;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (++counter < power)
	{
		nb = nb * aux;
	}
	return (nb);
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
	if (argc != 3)
		return (1);
	printf("Result: %d\n", ft_iterative_power(ft_atoi(argv[1]), ft_atoi(argv[2])));
}*/
