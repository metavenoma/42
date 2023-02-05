/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:33:40 by rverona-          #+#    #+#             */
/*   Updated: 2023/02/05 17:59:31 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int keycode, int x, int y, t_fractol *fractol)
{
	t_complex	center;

	center = init_c(((fractol->max.re - fractol->min.re) / WIDTH),
			((fractol->max.im - fractol->min.im) / HEIGHT));
	if (keycode == 4)
	{
		fractol->min.re = (fractol->min.re + ((center.re * x) * 0.1));
		fractol->max.re = (fractol->max.re
				- ((center.re * (WIDTH - x)) * 0.1));
		fractol->max.im = (fractol->max.im - ((center.im * y) * 0.1));
		fractol->min.im = (fractol->min.im
				+ ((center.im * (HEIGHT - y)) * 0.1));
		render(fractol);
	}
	if (keycode == 5)
	{
		fractol->min.re = (fractol->min.re - ((center.re * x) * 0.1));
		fractol->max.re = (fractol->max.re
				+ ((center.re * (WIDTH - x)) * 0.1));
		fractol->max.im = (fractol->max.im + ((center.im * y) * 0.1));
		fractol->min.im = (fractol->min.im
				- ((center.im * (HEIGHT - y)) * 0.1));
		render(fractol);
	}
	return (0);
}
