#include "printf_lib.h"

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
