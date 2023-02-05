/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:23:15 by rverona-          #+#    #+#             */
/*   Updated: 2023/02/05 18:44:52 by rverona-         ###   ########.fr       */
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
	end_rgb[0] = ((endcolor >>16) & 0xFF);
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
			fractol->palette[i + j] = interpolate(colors[x], colors[x + 1], fraction);
			j++;
		}
		x++;
		i += j;	
	}
	fractol->palette[MAX_ITERATION - 1] = 0;
}

void	get_color(t_fractol *fractol)
{
	set_color(fractol, (int [8]){0xFF0000, 0xFF7F00, 0xFFFF00, 0x00FF00, 
		0x0000FF, 0x4B0082, 0x9400D3, 0xFFFFFF}, 8);
}
