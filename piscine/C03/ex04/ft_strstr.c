/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:30:58 by rverona-          #+#    #+#             */
/*   Updated: 2022/07/26 16:23:31 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && str[i + j] != '\0')
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char a[] = "123874683746";
	char b[] = "683";

	printf("Valor de a: %s\nValor de b: %s\n", a, b);
	printf("Resultado strstr: %s\n", ft_strstr(a, b));
	printf("Resultado ft_strstr: %s\n", ft_strstr(a, b));
}*/
