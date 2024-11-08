/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:58:56 by rverona-          #+#    #+#             */
/*   Updated: 2024/05/10 10:58:57 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	end_fractol(t_fractol *f)
{
	if (!f)
	{
		exit(0);
		return (0);
	}
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win && f->mlx)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	if (f)
		free(f);
	exit(0);
	return (0);
}

int	set_fractal_layout(int keycode, t_fractol *f)
{
	if (keycode == K_ESCAPE)
		end_fractol(f);
	if (f->set == 2 && keycode == -1)
	{
		f->max.r = 2.0;
		f->max.i = -2.0;
		f->min.r = -2.0;
		f->min.i = f->max.i + (f->max.r - f->min.r) * (HEIGHT / W);
	}
	else if (f->set == 2 && keycode == -2)
	{
		f->c.r = 0.285;
		f->c.i = 0.01;
		f->z.r = f->min.r + (double)f->x * (f->max.r - f->min.r) / W;
		f->z.i = f->min.i + (double)f->y * (f->max.i - f->min.i) / HEIGHT;
		return (0);
	}
	else if (f->set == 1)
	{
		f->c.r = f->min.r + (double)f->x * (f->max.r - f->min.r) / W;
		f->c.i = f->min.i + (double)f->y * (f->max.i - f->min.i) / HEIGHT;
		return (0);
	}
	return (0);
}

int	handle_keypress(int keycode, int x, int y, t_fractol *f)
{
	t_complex	center;

	center.r = ((f->max.r - f->min.r) / W);
	center.i = ((f->max.i - f->min.i) / HEIGHT);
	if (keycode == MOUSE_UP)
	{
		f->min.r = (f->min.r + ((center.r * x) * 0.1));
		f->max.r = (f->max.r - ((center.r * (W - x)) * 0.1));
		f->max.i = (f->max.i - ((center.i * y) * 0.1));
		f->min.i = (f->min.i + ((center.i * (HEIGHT - y)) * 0.1));
		render(f);
	}
	if (keycode == MOUSE_DOWN)
	{
		f->min.r = (f->min.r - ((center.r * x) * 0.1));
		f->max.r = (f->max.r + ((center.r * (W - x)) * 0.1));
		f->max.i = (f->max.i + ((center.i * y) * 0.1));
		f->min.i = (f->min.i - ((center.i * (HEIGHT - y)) * 0.1));
		render(f);
	}
	return (0);
}

void	render(t_fractol *f)
{
	f->y = -1;
	while (++f->y < HEIGHT)
	{
		f->x = -1;
		while (++f->x < W)
		{
			f->i = -1;
			f->z.r = 0;
			f->z.i = 0;
			set_fractal_layout(-2, f);
			while (++f->i < MAX_ITERATION
				&& pow(f->z.r, 2.0) + pow(f->z.i, 2.0) <= 4.0)
			{
				f->temp = 2 * (f->z.r * f->z.i) + f->c.i;
				f->z.r = pow(f->z.r, 2.0)
					- pow(f->z.i, 2.0) + f->c.r;
				f->z.i = f->temp;
			}
			f->a[f->x * 4 + f->y * W * 4] = 0xFF4 * f->i;
			f->a[f->x * 4 + f->y * W * 4 + 1] = 0xFF7 * f->i >> 8;
			f->a[f->x * 4 + f->y * W * 4 + 2] = 0xFF5 * f->i >> 16;
			f->a[f->x * 4 + f->y * W * 4 + 3] = 0xFF2 * f->i >> 24;
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

int	main(int argc, char *argv[])
{
	t_fractol	*f;

	if (argc != 2 || (argv[1][0] != '1' && argv[1][0] != '2'))
	{
		write(2, "usage: ./fractol <set>\nsets: <1> mandelbrot <2> julia\n", 54);
		return (0);
	}
	f = (t_fractol *)malloc(sizeof(t_fractol));
	*f = (t_fractol){0};
	f->set = argv[1][0] - '0';
	f->min.r = -2.0;
	f->min.i = -1.5;
	f->max.r = 1.0;
	f->max.i = f->min.i + (f->max.r - f->min.r) * (HEIGHT / W);
	set_fractal_layout(-1, f);
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, W, HEIGHT, "Fract-ol");
	f->img = mlx_new_image(f->mlx, W, HEIGHT);
	f->a = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
	render(f);
	mlx_hook(f->win, 17, 0, end_fractol, f);
	mlx_key_hook(f->win, set_fractal_layout, f);
	mlx_mouse_hook(f->win, handle_keypress, f);
	mlx_loop(f->mlx);
}
