/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:33:01 by rverona-          #+#    #+#             */
/*   Updated: 2023/02/05 19:07:31 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_fractol(int exit_code, t_fractol *fractol)
{
	if (!fractol)
		exit(exit_code);
	if (fractol->palette)
		free(fractol->palette);
	if (fractol->img.image)
		mlx_destroy_image(fractol->mlx, fractol->img.image);
	if (fractol->win && fractol->mlx)
		mlx_destroy_window(fractol->mlx, fractol->win);
	if (fractol->mlx)
	{
		mlx_loop_end(fractol->mlx);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
	}
	exit(exit_code);
}

int	end_fractol(t_fractol *fractol)
{
	exit_fractol(0, fractol);
	return (0);
}
