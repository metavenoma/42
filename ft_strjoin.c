/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:19:09 by rverona-          #+#    #+#             */
/*   Updated: 2022/09/11 21:31:12 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int	i;
	int len;

	if (!(res = (char*)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		res[i] = *(char *)s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		res[i] = *(char *)s2;
		s2++;
		i++;
	}
	len = ft_strlen(res);
	res[len] = '\0';
	return (res);
}

/*int	main(void)
{
	char *ss = "aoooo coisa boa! ";
	char *sss = "sim";
	printf("%s", ft_strjoin(ss, sss));
}*/
