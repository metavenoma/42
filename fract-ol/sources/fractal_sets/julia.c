/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:34:23 by rverona-          #+#    #+#             */
/*   Updated: 2023/02/06 11:35:06 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_fractol *fractol, t_complex c)
{
	int			iteration;
	double		temp;
	t_complex	z;

	z = init_c(c.re, c.im);
	iteration = 0;
	while (iteration < MAX_ITERATION
		&& pow(z.re, 2.0) + pow(z.im, 2.0) <= 4.0)
	{
		temp = 2 * z.re * z.im + fractol->julia.im;
		z.re = pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->julia.re;
		z.im = temp;
		iteration++;
	}
	return (iteration);
}
