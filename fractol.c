#include "fractol.h"

void	img_pix_put(t_fractol *fractol, int x, int y, int color)
{
	fractol->img.addr[x * 4 + y * WIDTH * 4] = color;
	fractol->img.addr[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	fractol->img.addr[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	fractol->img.addr[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

void	set_fractal_layout(t_fractol *f)
{
	if (f->set == 2)
	{
		f->max.r = 2.0;
		f->max.i = -2.0;
		f->min.r = -2.0;
		f->min.i = f->max.i + (f->max.r - f->min.r) * (HEIGHT / WIDTH);
		f->c.r = 0.285;
		f->c.i = 0.01;
	}
	else
	{
		f->min.r = -2.0;
		f->min.i = -1.5;
		f->max.r = 1.0;
		f->max.i = f->min.i + (f->max.r - f->min.r) * (HEIGHT / WIDTH);
	}
}

int	handle_keypress(int keycode, int x, int y, t_fractol *f)
{
	t_complex	center;

	center.r = ((f->max.r - f->min.r) / WIDTH);
	center.i = ((f->max.i - f->min.i) / HEIGHT);
	if (keycode == K_ESCAPE)
		end_fractol(f);
	if (keycode == MOUSE_UP)
	{
		f->min.r = (f->min.r + ((center.r * x) * 0.1));
		f->max.r = (f->max.r - ((center.r * (WIDTH - x)) * 0.1));
		f->max.i = (f->max.i - ((center.i * y) * 0.1));
		f->min.i = (f->min.i + ((center.i * (HEIGHT - y)) * 0.1));
		render(f);
	}
	if (keycode == MOUSE_DOWN)
	{
		f->min.r = (f->min.r - ((center.r * x) * 0.1));
		f->max.r = (f->max.r + ((center.r * (WIDTH - x)) * 0.1));
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
		while (++f->x < WIDTH)
		{
			if (f->set == 1)
			{
				f->c.r = f->min.r + (double)x * (f->max.r - f->min.r) / WIDTH;
				f->c.i = f->min.i + (double)y * (f->max.i - f->min.i) / HEIGHT;
				f->iteration = -1;
			}
			while (++f->iteration < MAX_ITERATION
							&& pow(f->z.r, 2.0) + pow(f->z.i, 2.0) <= 4.0)
			{
				temp = 2 * f->z.r * f->z.i + f->c.i;
				f->z.r = pow(f->z.r, 2.0) - pow(f->z.i, 2.0) + f->c.r;
				f->z.i = temp;
			}
			img_pix_put(f, f->x, f->y, 0xFFF44336 * f->iteration);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

int	main(int argc, char *argv[])
{
	t_fractol	f;

	if (argc != 2 || (argv[1][0] != '1' && argv[1][0] !=  '2'))
		write(2, "usage: ./fractol <set>\nsets: <1> mandelbrot\n<2> julia\n", 54);
	f.set = argv[1] - '0';
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fract-ol");
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	f.addr = mlx_get_data_addr(f.img, &f.bpp, &f.line_len, &f.endian);
}
