/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:33:54 by rverona-          #+#    #+#             */
/*   Updated: 2023/02/05 18:45:12 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*void	img_pix_put(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(int *)(img->addr + ((x + y * WIDTH) * img->bpp)) = color;
}*/

/*void	img_pix_put(t_fractol *fractol, int x, int y, int color)
{
	fractol->buff[x * 4 + y * WIDTH * 4] = color;
	fractol->buff[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	fractol->buff[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	fractol->buff[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}*/

void	img_pix_put(t_fractol *fractol, int x, int y, int color)
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
}

int	check_fractal(t_fractol *fractol)
{
	int	iteration;

	if (fractol->set == 1)
		iteration = mandelbrot(fractol);
	if (fractol->set == 2)
		iteration = julia(fractol);
	return (iteration);
}

void	set_layout(t_fractol *fractol)
{
	if (fractol->set == 1)
	{
		fractol->min = init_c(-2.0, -2.0);
		fractol->max.re = 2.0;
		fractol->max.im = fractol->min.im + (fractol->max.re
				- fractol->min.re) * (HEIGHT / WIDTH);
	}
	if (fractol->set == 2)
	{
		fractol->max = init_c(2.0, -2.0);
		fractol->min.re = -2.0;
		fractol->min.im = fractol->max.im + (fractol->max.re
				- fractol->min.re) * HEIGHT / WIDTH;
	}
	fractol->factor = init_c((fractol->max.re - fractol->min.re) / WIDTH,
			(fractol->max.im - fractol->min.im) / HEIGHT);
	fractol->julia = init_c(-0.70176, -0.3842);
	fractol->mlx = NULL;
	fractol->win = NULL;
	fractol->img.image = NULL;
}

void	render(t_fractol *fractol)
{
	int	x;
	int	y;
	int	iteration;

	y = 0;
	while (y < HEIGHT)
	{
		fractol->c.im = fractol->min.im + (double)y
			* (fractol->max.im - fractol->min.im) / HEIGHT;
		x = 0;
		while (x < WIDTH)
		{
			fractol->c.re = fractol->min.re + (double)x
				* (fractol->max.re - fractol->min.re) / WIDTH;
			iteration = check_fractal(fractol);
			/*if (iteration == MAX_ITERATION)
				color = 0x020713;
			else
				color = 0x00738D9A * iteration;*/
			img_pix_put(fractol, x, y, fractol->palette[iteration]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->img.image, 0, 0);
}
