#include "libft.h"

void    ft_putnbr_fd(int nb, int fd)
{
        if (nb == -2147483648)
        {
                nb = 147483648;
                ft_putchar_fd('-', fd);
                ft_putchar_fd('2', fd);
        }
        if (nb < 0)
        {
                ft_putchar_fd('-', fd);
                nb *= -1;
        }
        if (nb < 10)
        {
                ft_putchar_fd(nb + '0', fd);
                return ;
        }
        else
                ft_putnbr(nb / 10, fd);
        ft_putnbr(nb % 10, fd);
}