#include "printf_lib.h"

int	printhex(unsigned long nbr, char *base)
{
	int	printhex_len;

	printhex_len = 0;
	if (nbr >= 16)
		printhex_len += printhex(nbr / 16, base);
	printhex_len += printchar(base[nbr % 16]);
	return (printhex_len);
}
