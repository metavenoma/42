/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:34:15 by rverona-          #+#    #+#             */
/*   Updated: 2023/02/06 15:55:33 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	tricorn(t_complex c)
{
	int			iteration;
	t_complex	z;

	z.re = 0;
	z.im = 0;
	iteration = 0;
	while (iteration < MAX_ITERATION
		&& pow(z.re, 2.0) + pow(z.im, 2.0) <= 4.0)
	{
		z = init_c(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
				- 2.0 * (z.re * z.im) + c.im);
		iteration++;
	}
	return (iteration);
}
