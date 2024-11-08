/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:25:19 by rverona-          #+#    #+#             */
/*   Updated: 2023/02/06 15:57:36 by rverona-         ###   ########.fr       */
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
	else if (keycode == K_C)
	{
		if (fractol->palette_set == 6)
			fractol->palette_set = 0;
		else
			fractol->palette_set++;
		get_color(fractol);
	}
	else if (keycode == K_ONE || keycode == K_TWO || keycode == K_THREE
		|| keycode == K_FOUR || keycode == K_FIVE
		|| keycode == K_SIX || keycode == K_SEVEN
		|| keycode == K_EIGHT || keycode == K_NINE)
		change_set(fractol, keycode);
	else if (keycode == K_LEFT || keycode == K_RIGHT
		|| keycode == K_UP || keycode == K_DOWN)
		move(fractol, keycode);
	else
		return (1);
	render(fractol);
	return (0);
}

void	change_set(t_fractol *fractol, int keycode)
{
	if (keycode == K_ONE)
		fractol->set = 1;
	else if (keycode == K_TWO)
		fractol->set = 2;
	else if (keycode == K_THREE)
		fractol->set = 3;
	else if (keycode == K_FOUR)
		fractol->set = 4;
	else if (keycode == K_FIVE)
		fractol->set = 5;
	else if (keycode == K_SIX)
		fractol->set = 6;
	else if (keycode == K_SEVEN)
		fractol->set = 7;
	else if (keycode == K_EIGHT)
		fractol->set = 8;
	else if (keycode == K_NINE)
		fractol->set = 9;
	else if (keycode == K_ZERO)
		fractol->set = 0;
	set_fractal_layout(fractol);
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
