/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:26:03 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/20 15:18:28 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	printhex(unsigned long nbr, char *base)
{
	int	printhex_len;

	printhex_len = 0;
	if (nbr >= 16)
		printhex_len += printhex(nbr / 16, base);
	printhex_len += printchar(base[nbr % 16]);
	return (printhex_len);
}
