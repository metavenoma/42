/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 03:40:15 by rverona-          #+#    #+#             */
/*   Updated: 2022/07/27 12:04:58 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (nb * ft_recursive_power(nb, power - 1));
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
	printf("Result: %d\n", ft_recursive_power(ft_atoi(argv[1]), ft_atoi(argv[2])));
}*/
