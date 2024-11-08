/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:10:17 by rverona-          #+#    #+#             */
/*   Updated: 2022/08/31 22:50:28 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	i;

	if (min >= max)
		return (NULL);
	res = (int *)malloc(sizeof(int) * (max - min));
	i = 0;
	while (min < max)
	{
		res[i] = min;
		min++;
		i++;
	}
	return (res);
}
