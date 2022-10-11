/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 23:38:47 by rverona-          #+#    #+#             */
/*   Updated: 2022/10/06 22:55:15 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int	n)
{
	int size;
	char *s;

	size = count_num(n);
	s = (char *)malloc(sizeof(char)*(size +1));

	if(!s)
		return(NULL);
	s[size] = '\0';
	size--;

	while(size >= 0)
	{
		s[size] = n % 10 + 48;
		n = n / 10;
		size--;
	}
	if(n < 0)
	{
		n =  n * -1;
		s[0] = "-";
	}
	return (s);
}

int	count_num(int n)
{
	int i;

	i = 1; 
	while(n >= 10)
	{
		n = n / 10;
		i++;
	}
	if(n < 0)
		i++;
	return (i);
}
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