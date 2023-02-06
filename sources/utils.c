/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:34:05 by rverona-          #+#    #+#             */
/*   Updated: 2023/02/06 15:58:26 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	s;

	s = 0;
	while (str[s] != '\0')
	{
		ft_putchar_fd(str[s], fd);
		s++;
	}
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pt;

	if ((!nmemb || !size) || size > SIZE_MAX / nmemb)
		return (NULL);
	pt = (void *)malloc(nmemb * size);
	ft_bzero(pt, nmemb * size);
	return (pt);
}
