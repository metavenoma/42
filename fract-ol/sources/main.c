/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:33:33 by rverona-          #+#    #+#             */
/*   Updated: 2023/02/06 15:56:59 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	if (argc != 2 || (argv[1][0] != '1' && argv[1][0] != '2'
		&& argv[1][0] != '3' && argv[1][0] != '4'
		&& argv[1][0] != '5' && argv[1][0] != '6'
		&& argv[1][0] != '7' && argv[1][0] != '8'
		&& argv[1][0] != '9' && argv[1][0] != '0'))
		print_help(&fractol);
	fractol.set = argv[1][0] - '0';
	set_fractal_layout(&fractol);
	set_layout(&fractol);
	init(&fractol);
	render(&fractol);
	mlx_hook(fractol.win, 17, 0, end_fractol, &fractol);
	mlx_key_hook(fractol.win, handle_keypress, &fractol);
	mlx_mouse_hook(fractol.win, handle_mouse, &fractol);
	mlx_loop(fractol.mlx);
}
