/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:25:31 by rverona-          #+#    #+#             */
/*   Updated: 2022/12/08 22:33:16 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printstr(char *str)
{
	int	printstr_len;

	printstr_len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[printstr_len])
	{
		printchar(str[printstr_len]);
		printstr_len++;
	}
	return (printstr_len);
}
