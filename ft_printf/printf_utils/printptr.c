/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:26:56 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/20 15:18:56 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

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
