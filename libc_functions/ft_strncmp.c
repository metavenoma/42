/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 00:51:37 by rverona-          #+#    #+#             */
/*   Updated: 2022/09/03 21:25:02 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	if (n == 0)
		return (0);
	while ((s1[++i] == s2[i]) && (i < n - 1))
		;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
