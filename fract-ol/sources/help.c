/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:33:09 by rverona-          #+#    #+#             */
/*   Updated: 2023/02/05 18:00:03 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help(t_fractol *fractol)
{
	ft_putendl_fd("+=============================================+", 1);
	ft_putendl_fd(" _____ _____ _____ _____ _____     _____ __ ", 1);
	ft_putendl_fd("|   __| __  |  _  |     |_   _|___|     |  |", 1);
	ft_putendl_fd("|   __|    -|     |   --| | | |___|  |  |  |__", 1);
	ft_putendl_fd("|__|  |__|__|__|__|_____| |_|     |_____|_____|", 1);
	ft_putendl_fd("                                               ", 1);
	ft_putendl_fd("+============Available Fractal Sets===========+", 1);
	ft_putendl_fd("     [1] ------------ Mandelbrot set", 1);
	ft_putendl_fd("     [2] ------------ Julia set", 1);
	ft_putendl_fd("+=============Available Movements=============+", 1);
	ft_putendl_fd("     [Arrow keys] --- Move view", 1);
	ft_putendl_fd("     [Mouse wheel] -- Zoom in and out", 1);
	ft_putendl_fd("     [1, 2] --------- Switch fractals", 1);
	ft_putendl_fd("     [ESC] ---------- Quit Fract-ol", 1);
	ft_putendl_fd("+=============================================+", 1);
	end_fractol(fractol);
}
