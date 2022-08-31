/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:05:59 by rverona-          #+#    #+#             */
/*   Updated: 2022/07/12 18:59:38 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_two(char d)
{
	ft_putchar(d / 10 + '0');
	ft_putchar(d % 10 + '0');
}

void	ft_print_comb2(void)
{
	char	num1;
	char	num2;

	num1 = 0;
	while (num1 <= 98)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			ft_print_two(num1);
			ft_putchar(' ');
			ft_print_two(num2);
			if (num1 < 98)
			{	
				ft_putchar(',');
				ft_putchar(' ');
			}
			num2++;
		}
		num1++;
	}
}
