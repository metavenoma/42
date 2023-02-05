/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:34:15 by rverona-          #+#    #+#             */
/*   Updated: 2023/02/05 18:11:54 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	z.re = 0;
	z.im = 0;
	iteration = 0;
	while (iteration < MAX_ITERATION
		&& pow(z.re, 2.0) + pow(z.im, 2.0) <= 4.0)
	{
		z = init_c(pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->c.re,
				2.0 * (z.re * z.im) + fractol->c.im);
		iteration++;
	}
	return (iteration);
}
