#include "printf_lib.h"

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
