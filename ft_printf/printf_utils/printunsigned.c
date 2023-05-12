/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:26:09 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/20 15:19:30 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	printunsigned(unsigned int nbr)
{
	int	printunsigned_len;

	printunsigned_len = 0;
	if (nbr < 10)
	{
		printunsigned_len += printchar(nbr + 48);
		return (printunsigned_len);
	}
	else
		printunsigned_len += printunsigned(nbr / 10);
	printunsigned_len += printunsigned(nbr % 10);
	return (printunsigned_len);
}
