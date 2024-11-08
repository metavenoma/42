/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:59:02 by rverona-          #+#    #+#             */
/*   Updated: 2024/05/10 10:59:03 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define W 500
# define HEIGHT 500
# define MAX_ITERATION 100

# include <mlx.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <math.h>
# include <unistd.h>

# define K_ESCAPE 65307
# define MOUSE_UP 4
# define MOUSE_DOWN 5

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*a;
	int			bpp;
	int			line_len;
	int			endian;
	int			set;
	int			x;
	int			y;
	int			i;
	double		temp;
	t_complex	c;
	t_complex	z;
	t_complex	julia;
	t_complex	max;
	t_complex	min;
	t_complex	factor;
}	t_fractol;

int		end_fractol(t_fractol *f);
int		set_fractal_layout(int keycode, t_fractol *f);
int		handle_keypress(int keycode, int x, int y, t_fractol *f);
void	render(t_fractol *f);

#endif
