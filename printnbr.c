/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:25:51 by rverona-          #+#    #+#             */
/*   Updated: 2022/12/09 00:40:55 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printnbr(int nbr)
{
	int	printnbr_len;

	printnbr_len = 0;
	if (nbr == -2147483648)
	{
		printnbr_len += printchar('-');
		printnbr_len += printchar('2');
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		printnbr_len += printchar('-');
		nbr *= -1;
	}
	if (nbr < 10)
	{
		printnbr_len += printchar(nbr + 48);
		return (printnbr_len);
	}
	else
	{
		printnbr_len += printnbr(nbr / 10);
	}
	printnbr_len += printnbr(nbr % 10);
	return (printnbr_len);
}
