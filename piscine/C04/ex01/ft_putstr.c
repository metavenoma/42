/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:58:17 by rverona-          #+#    #+#             */
/*   Updated: 2022/07/26 13:55:22 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	s;

	s = 0;
	while (str[s] != '\0')
	{
		ft_putchar(str[s]);
		s++;
	}
}
/*
int	main(void)
{
	char	a[] = "Print me!\n";
	ft_putstr(a);
}*/
