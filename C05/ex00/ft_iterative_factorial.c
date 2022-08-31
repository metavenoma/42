/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interative_factorial.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:35:37 by rverona-          #+#    #+#             */
/*   Updated: 2022/07/27 14:02:51 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	aux;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	aux = nb - 1;
	while (aux > 0)
	{
		nb *= aux--;
	}
	if (nb)
		return (nb);
	else
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
	printf("Result: %d\n", ft_iterative_factorial(ft_atoi(argv[1])));
}*/
