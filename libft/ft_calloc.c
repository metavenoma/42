/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:58:04 by rverona-          #+#    #+#             */
/*   Updated: 2022/09/07 19:43:37 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pt;

	if ((!nmemb || !size) || size > SIZE_MAX / nmemb)
		return (NULL);
	pt = (void *)malloc(nmemb * size);
	ft_bzero(pt, nmemb * size);
	return (pt);
}
