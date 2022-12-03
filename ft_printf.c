#include "printf_lib.h"

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
	int	printf_len;

	printf_len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			printf_len += convert_specifier(&args, *++str);
		else if (*str)
			printf_len += printchar(*str);
		str++;
	}
	va_end(args);
	return (printf_len);
}
