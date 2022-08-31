/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:20:17 by rverona-          #+#    #+#             */
/*   Updated: 2022/09/01 01:04:20 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	x;
	int	capital;

	x = 0;
	capital = 1;
	while (str[x] != '\0')
	{
		if (capital == 1 && (str[x] >= 97 && str[x] <= 122))
			str[x] -= 32;
		else if (capital == 0 && (str[x] >= 65 && str[x] <= 90))
			str[x] += 32;
		if ((str[x] < 48 || (str[x] > 57 && str[x] < 90)) || 
			(str[x] > 90 && str[x] < 97))
			capital = 1;
		else
			capital = 0;
		x++;
	}
	return (str);
}
