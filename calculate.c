/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:12:34 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/31 13:46:26 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_z_c(t_fractol *fractol)
{
	if (fractol->set == 'M' || fractol->set == 'B')
	{
		fractol->zx = 0.;
		fractol->zy = 0.;
		fractol->cx = fractol->x / fractol->zoom + fractol->offset_x;
		fractol->cy = fractol->y / fractol->zoom + fractol->offset_y;
	}
	else if (fractol->set == 'J')
	{
		fractol->zx = fractol->x / fractol->zoom + fractol->offset_x;
		fractol->zy = fractol->y / fractol->zoom + fractol->offset_y;
		if (fractol->cx == 0 && fractol->cy == 0)
		{
			fractol->cx = -0.745429;
			fractol->cy = 0.05;
		}
	}
}

void	calculate_mandelbrot(t_fractol *fractol)
{
	int		i;
	int		c;
	double	x_tmp;

	i = 0;
	set_z_c(fractol);
	while (fractol->zx * fractol->zx + fractol->zy * fractol->zy < 4.
		&& i < fractol->max_iter)
	{
		x_tmp = fractol->zx * fractol->zx - fractol->zy * fractol->zy
			+ fractol->cx;
		fractol->zy = 2. * fractol->zx * fractol->zy + fractol->cy;
		fractol->zx = x_tmp;
		i++;
	}
	if (i == fractol->max_iter)
		fractol->color = 0x000000;
	else
	{
		c = i % 16;
		fractol->color = color_mandelbrot(c) + fractol->color_change;
	}
}

void	calculate_julia(t_fractol *fractol)
{
	int		i;
	double	x_tmp;

	i = 0;
	set_z_c(fractol);
	while (fractol->zx * fractol->zx + fractol->zy * fractol->zy < 4.
		&& i < fractol->max_iter)
	{
		x_tmp = fractol->zx;
		fractol->zx = fractol->zx * fractol->zx - fractol->zy * fractol->zy
			+ fractol->cx;
		fractol->zy = 2 * fractol->zy * x_tmp + fractol->cy;
		i++;
	}
	if (i == fractol->max_iter)
		fractol->color = 0x000000;
	else
		fractol->color = color_julia(i) + fractol->color_change;
}

void	calculate_burning_ship(t_fractol *fractol)
{
	int		i;
	double	x_tmp;

	i = 0;
	set_z_c(fractol);
	while (fractol->zx * fractol->zx + fractol->zy * fractol->zy < 4.
		&& i < fractol->max_iter)
	{
		x_tmp = fractol->zx * fractol->zx - fractol->zy * fractol->zy
			+ fractol->cx;
		fractol->zy = fabs(2. * fractol->zx * fractol->zy) + fractol->cy;
		fractol->zx = fabs(x_tmp);
		i++;
	}
	if (i == fractol->max_iter)
		fractol->color = 0x000000;
	else
		fractol->color = 0x6e820f * i / 100 + fractol->color_change;
}
