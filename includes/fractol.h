/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:15:48 by rverona-          #+#    #+#             */
/*   Updated: 2023/02/05 19:00:01 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH	500
# define HEIGHT 500
# define MAX_ITERATION 30

# include <mlx.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <math.h>

typedef struct s_complex
{
	double	re;	
	double	im;
}	t_complex;

typedef struct s_img
{
	void	*image;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	char		*buff;
	int			set;
	int			*palette;
	t_img		img;
	t_complex	c;
	t_complex	julia;
	t_complex	max;
	t_complex	min;
	t_complex	factor;
}		t_fractol;

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			interpolate(int startcolor, int endcolor, double fraction);
void		set_color(t_fractol *fractol, int colors[4], int n);
void		get_color(t_fractol *fractol);
void		fd_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *str, int fd);
int			check_fractal(t_fractol *fractol);
int			mandelbrot(t_fractol *fractol);
int			julia(t_fractol *fractol);
void		render(t_fractol *fractol);
void		set_layout(t_fractol *fractol);
t_complex	init_c(double re, double im);
void		exit_fractol(int exit_code, t_fractol *fractol);
int			end_fractol(t_fractol *fractol);
void		zoom(t_fractol *fractol, double zoom);
void		init(t_fractol *fractol);
int			handle_mouse(int keycode, int x, int y, t_fractol *fractol);
void		move(t_fractol *fractol, int keycode);
void		move_julia(t_fractol *fractol, int keycode);
void		img_pix_put(t_fractol *fractol, int x, int y, int color);
int			handle_keypress(int keycode, t_fractol *fractol);
void		print_help(t_fractol *fractol);
#endif
