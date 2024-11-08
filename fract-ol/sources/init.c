/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:33:16 by rverona-          #+#    #+#             */
/*   Updated: 2023/02/05 19:06:10 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractol *fractol)
{
	fractol->palette = ft_calloc((MAX_ITERATION + 1), sizeof(int));
	if (!(fractol->palette))
		end_fractol(fractol);
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		exit_fractol(1, fractol);
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!fractol->win)
		exit_fractol(1, fractol);
	fractol->img.image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img.image)
		exit_fractol(1, fractol);
	fractol->img.addr = mlx_get_data_addr(fractol->img.image,
			&fractol->img.bpp, &fractol->img.line_len,
			&fractol->img.endian);
	get_color(fractol);
}
