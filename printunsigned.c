#include "printf_lib.h"

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
