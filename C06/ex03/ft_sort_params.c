/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 08:48:21 by rverona-          #+#    #+#             */
/*   Updated: 2022/07/28 16:28:00 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0' || *s2 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (++j < argc - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				aux = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = aux;
			}
		}
	}
	i = 0;
	while (++i < argc)
	{		
		ft_putstr(argv[i]);
		ft_putchar('\n');
	}
}
