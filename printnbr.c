#include "printf_lib.h"

int	printnbr(int nbr)
{
	int	printnbr_len;

	printnbr_len = 0;
	if (nbr == -2147483648)
		printnbr_len += printstr("-2147483648");
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
		printnbr(nbr / 10);
	printnbr(nbr % 10);
	return (printnbr_len);
}
