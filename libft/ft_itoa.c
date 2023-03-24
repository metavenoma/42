/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 23:38:47 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/20 15:44:03 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	{
		s[0] = '-';
	}
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

/*int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
}*/
/*#include "libft.h"

char	*ft_itoa(int n)
{
	int	i;
	int j;
	int	bkp;
	char	*res;
	char	*neg;

	i = 1;
	bkp = n;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	if (n < 0)
		i++;
	if (!(res = ((char *)malloc((i + 1) * (sizeof(char))))))
		return (NULL);
	res[i] = '\0';
	i--;
	while (i >= 0)
	{
		res[i] = bkp % 10 + 48;
		bkp = bkp / 10;
		i--;
	}
	j = 1;
	if (n < 0)
	{
		res[0] = '-';
		while (j <= ft_strlen(res))
		{
			res[j] = res[i];
			i++;
			j++;
		}
	}
	return (res);
}*/
