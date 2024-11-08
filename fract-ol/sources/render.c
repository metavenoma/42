/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:33:54 by rverona-          #+#    #+#             */
/*   Updated: 2023/02/06 16:05:17 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pix_put(t_fractol *fractol, int x, int y, int color)
{
	fractol->img.addr[x * 4 + y * WIDTH * 4] = color;
	fractol->img.addr[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	fractol->img.addr[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	fractol->img.addr[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

/*void	img_pix_put(t_fractol *fractol, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = fractol->img.bpp - 8;
	pixel = fractol->img.addr + (y * fractol->img.line_len
			+ x * (fractol->img.bpp / 8));
	while (i >= 0)
	{
		if (fractol->img.endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (fractol->img.bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}*/

int	check_fractal(t_fractol *fractol, t_complex c)
{
	int	iteration;

	if (fractol->set == 1)
		iteration = mandelbrot(c);
	if (fractol->set == 2)
		iteration = julia(fractol, c);
	if (fractol->set == 3)
		iteration = burning_ship(c);
	if (fractol->set == 4)
		iteration = tricorn(c);
	if (fractol->set == 5)
		iteration = perpendicular_mandelbrot(c);
	if (fractol->set == 6)
		iteration = perpendicular_buffalo(c);
	if (fractol->set == 7)
		iteration = perpendicular_burning_ship(c);
	if (fractol->set == 8)
		iteration = celtic_mandelbrot(c);
	if (fractol->set == 9)
		iteration = celtic_mandelbar(c);
	if (fractol->set == 0)
		iteration = celtic_perpendicular(c);
	return (iteration);
}

void	set_fractal_layout(t_fractol *fractol)
{
	if (fractol->set == 2)
	{
		fractol->max = init_c(2.0, -2.0);
		fractol->min.re = -2.0;
		fractol->min.im = fractol->max.im + (fractol->max.re
				- fractol->min.re) * (HEIGHT / WIDTH);
	}
	else
	{
		fractol->min = init_c(-2.0, -1.5);
		fractol->max.re = 1.0;
		fractol->max.im = fractol->min.im + (fractol->max.re
				- fractol->min.re) * (HEIGHT / WIDTH);
	}
}

void	set_layout(t_fractol *fractol)
{
	fractol->factor = init_c((fractol->max.re - fractol->min.re) / WIDTH,
			(fractol->max.im - fractol->min.im) / HEIGHT);
	fractol->julia = init_c(0.285, 0.01);
	fractol->palette_set = 0;
	fractol->mlx = NULL;
	fractol->win = NULL;
	fractol->img.image = NULL;
}

void	render(t_fractol *fractol)
{
	int			x;
	int			y;
	t_complex	c;
	int			iteration;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.re = fractol->min.re + (double)x
				* (fractol->max.re - fractol->min.re) / WIDTH;
			c.im = fractol->min.im + (double)y
				* (fractol->max.im - fractol->min.im) / HEIGHT;
			iteration = check_fractal(fractol, c);
			img_pix_put(fractol, x, y, fractol->palette[iteration]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->img.image, 0, 0);
}
