#pragma once

#define WIDTH 600
#define HEIGHT 600
#define MAX_ITERATION 200

#include <mlx.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <math.h>

#define K_ESCAPE 65307
#define MOUSE_UP 4
#define MOUSE_DOWN 5

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
	void	*mlx;
	void	*win;
	int		set;
	t_img	img;
	t_complex	c;
	t_complex	julia;
	t_complex	max;
	t_complex	min;
	t_complex	factor;
}	t_fractol;
