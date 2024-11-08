/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 03:53:56 by rverona-          #+#    #+#             */
/*   Updated: 2022/07/27 12:05:08 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
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
	printf("Result: %d\n", ft_fibonacci(ft_atoi(argv[1])));
}*/
