/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 23:38:47 by rverona-          #+#    #+#             */
/*   Updated: 2022/10/13 22:15:44 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	count_num(int n);
int	ft_abs(int n);

char	*ft_itoa(int n)
{
	int		size;
	char	*s;

	size = count_num(n);
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	s[size] = '\0';
	size--;
	if (n < 0)
		s[0] = '-';
	else if (n == 0)
		s[0] = '0';
	while (n != 0)
	{
		s[size] = ft_abs(n % 10) + 48;
			n = n / 10;
		size--;
	}
	return (s);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	count_num(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
