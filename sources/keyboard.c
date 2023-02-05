/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:25:19 by rverona-          #+#    #+#             */
/*   Updated: 2023/02/05 18:06:44 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keyhook.h"

int	handle_keypress(int keycode, t_fractol *fractol)
{
	if (keycode == K_ESCAPE)
	{
		end_fractol(fractol);
		return (0);
	}
	else if (keycode == K_LEFT || keycode == K_RIGHT
		|| keycode == K_UP || keycode == K_DOWN)
		move(fractol, keycode);
	else
		return (1);
	render(fractol);
	return (0);
}

void	move(t_fractol *fractol, int keycode)
{	
	if (fractol->set == 2)
		move_julia(fractol, keycode);
	else if (keycode == K_RIGHT)
	{
		fractol->min.re += 0.05;
		fractol->max.re += 0.05;
	}
	else if (keycode == K_LEFT)
	{
		fractol->min.re -= 0.05;
		fractol->max.re -= 0.05;
	}
	else if (keycode == K_DOWN)
	{
		fractol->min.im += 0.05;
		fractol->max.im += 0.05;
	}
	else if (keycode == K_UP)
	{
		fractol->min.im -= 0.05;
		fractol->max.im -= 0.05;
	}	
}

void	move_julia(t_fractol *fractol, int keycode)
{
	if (keycode == K_RIGHT)
	{
		fractol->min.re += 0.05;
		fractol->max.re += 0.05;
	}
	else if (keycode == K_LEFT)
	{
		fractol->min.re -= 0.05;
		fractol->max.re -= 0.05;
	}
	else if (keycode == K_DOWN)
	{
		fractol->min.im -= 0.05;
		fractol->max.im -= 0.05;
	}
	else if (keycode == K_UP)
	{
		fractol->min.im += 0.05;
		fractol->max.im += 0.05;
	}
}
