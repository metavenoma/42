#include "printf_lib.h"

int	printchar(char c)
{
	write(1, &c, 1);
	return (1);
}
