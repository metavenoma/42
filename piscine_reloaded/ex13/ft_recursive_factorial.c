/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:59:35 by rverona-          #+#    #+#             */
/*   Updated: 2022/08/26 23:04:06 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if ((nb == 0) || (nb == 1))
		return (1);
	if (nb > 12)
		return (0);
	if (nb > 1)
	{
		nb = nb * ft_recursive_factorial(nb - 1);
	}
	return (nb);
}
