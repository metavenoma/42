/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:27:17 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/20 15:17:12 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	convert_specifier(va_list *args, char specifier)
{
	int	specifier_len;

	specifier_len = 0;
	if (specifier == 'c')
		specifier_len += printchar(va_arg(*args, int));
	else if (specifier == 's')
		specifier_len += printstr(va_arg(*args, char *));
	else if (specifier == 'p')
		specifier_len += printptr(va_arg(*args, unsigned long), HEX_LOW);
	else if (specifier == 'd' || specifier == 'i')
		specifier_len += printnbr(va_arg(*args, int));
	else if (specifier == 'u')
		specifier_len += printunsigned(va_arg(*args, unsigned int));
	else if (specifier == 'x')
		specifier_len += printhex(va_arg(*args, unsigned int), HEX_LOW);
	else if (specifier == 'X')
		specifier_len += printhex(va_arg(*args, unsigned int), HEX_UP);
	else if (specifier == '%')
		specifier_len += printchar('%');
	return (specifier_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		printf_len;

	if (!str)
		return (-1);
	va_start(args, str);
	printf_len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			printf_len += convert_specifier(&args, str[i]);
		}
		else
			printf_len += printchar(str[i]);
		i++;
	}
	va_end(args);
	return (printf_len);
}
