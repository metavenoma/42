/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:51:42 by rverona-          #+#    #+#             */
/*   Updated: 2022/09/06 22:51:52 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t l_s;

	l_s = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (l_s < len && *big != '\0')
	{
		if (*big == *little && ft_strncmp(big, little, l_s) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
