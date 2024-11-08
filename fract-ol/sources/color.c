/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:23:15 by rverona-          #+#    #+#             */
/*   Updated: 2023/02/06 16:03:54 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	interpolate(int startcolor, int endcolor, double fraction)
{
	int	rgb[3];
	int	end_rgb[3];

	rgb[0] = ((startcolor >> 16) & 0xFF);
	rgb[1] = ((startcolor >> 8) & 0xFF);
	rgb[2] = ((startcolor >> 0) & 0xFF);
	end_rgb[0] = ((endcolor >> 16) & 0xFF);
	end_rgb[1] = ((endcolor >> 8) & 0xFF);
	end_rgb[2] = ((endcolor >> 0) & 0xFF);
	rgb[0] = (end_rgb[0] - rgb[0]) * fraction + rgb[0];
	rgb[1] = (end_rgb[1] - rgb[1]) * fraction + rgb[1];
	rgb[2] = (end_rgb[2] - rgb[2]) * fraction + rgb[2];
	return (0xFF << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb [2]);
}

void	set_color(t_fractol *fractol, int colors[4], int n)
{
	int		i;
	int		j;
	int		x;
	double	fraction;

	i = 0;
	x = 0;
	while (i < MAX_ITERATION)
	{
		j = 0;
		while ((i + j) < MAX_ITERATION && j < (MAX_ITERATION / (n - 1)))
		{
			fraction = (double)j / (MAX_ITERATION / (n - 1));
			fractol->palette[i + j] = interpolate(colors[x],
					colors[x + 1], fraction);
			j++;
		}
		x++;
		i += j;
	}
	fractol->palette[MAX_ITERATION - 1] = 0;
}

void	get_color(t_fractol *fractol)
{
	if (fractol->palette_set == 0)
	{
		set_color(fractol, (int [8]){0x75D5FD, 0x96A1FD, 0xB76CFD,
			0xDB47BF, 0xFF2281, 0x8021BF, 0x011FFD, 0x4120DE}, 8);
	}
	else if (fractol->palette_set == 1)
	{
		set_color(fractol, (int [8]){0x0E402D, 0x00805B, 0x0D807C,
			0x30305B, 0x4151B1, 0x5E416D, 0x3F1D6D, 0x2E1452}, 8);
	}
	else if (fractol->palette_set == 2)
	{
		set_color(fractol, (int [8]){0xFF0000, 0xFF7F00, 0xFFFF00,
			0x00FF00, 0x0000FF, 0x4B0082, 0x9400D3, 0xFFFFFF}, 8);
	}
	else if (fractol->palette_set == 3)
	{
		set_color(fractol, (int [8]){0xFFE2C2, 0xFFC485, 0xFFA647,
			0xF79C3B, 0xC97D2C, 0x834F17, 0x48341F, 0x392918}, 8);
	}
	else if (fractol->palette_set > 3)
		get_color_plus(fractol);
}

void	get_color_plus(t_fractol *fractol)
{
	if (fractol->palette_set == 4)
	{
		set_color(fractol, (int [8]){0xFFFF66, 0xFEB744, 0xFC6E22,
			0xFE415B, 0xFF2B77, 0xFF1493, 0xE130C5, 0xC24CF6}, 8);
	}
	else if (fractol->palette_set == 5)
	{
		set_color(fractol, (int [8]){0xFF5252, 0xF8663A, 0xDE5A02,
			0xA39A03, 0x56D402, 0xEB0448, 0xA2037B, 0x5802AE}, 8);
	}
	else if (fractol->palette_set == 6)
	{
		set_color(fractol, (int [8]){0xFD7500, 0xFE8A02, 0xFF9F03,
			0x81AA51, 0x02B59F, 0x029581, 0x017562, 0x022422}, 8);
	}
}
