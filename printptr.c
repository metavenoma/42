/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:26:56 by rverona-          #+#    #+#             */
/*   Updated: 2022/12/08 22:33:01 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printptr(unsigned long ptr, char *base)
{
	int	printptr_len;

	printptr_len = 0;
	if (!ptr)
		return (printstr(SYS_NIL));
	printptr_len += printstr("0x");
	printptr_len += printhex(ptr, base);
	return (printptr_len);
}
