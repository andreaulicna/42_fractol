/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:57:50 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/26 16:14:29 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	set_cx_cy(t_fractol *fractol)
{
	if (fractol->set == 'M')
	{
		fractol->cx = fractol->x / fractol->zoom + fractol->offset_x;
		fractol->cy = fractol->y / fractol->zoom + fractol->offset_y;
	}
	else
	{
		fractol->cx = fractol->x / fractol->zoom + fractol->offset_x;
		fractol->cy = fractol->y / fractol->zoom + fractol->offset_y;
	}
}

void	calculate_mandelbrot(t_data *img, t_fractol *fractol)
{
	int	i;
	double	x_tmp;

	i = 0;
	set_cx_cy(fractol);
	fractol->zx = 0.;
	fractol->zy = 0.;
	while (fractol->zx * fractol->zx + fractol->zy * fractol->zy < __DBL_MAX__
		&& i < MAX_ITERATIONS)
	{
		x_tmp = fractol->zx * fractol->zx - fractol->zy * fractol->zy
			+ fractol->cx;
		fractol->zy = 2. * fractol->zx * fractol->zy + fractol->cy;
		fractol->zx = x_tmp;
		i++;
	}
	if (i == MAX_ITERATIONS)
		my_mlx_pixel_put(img, fractol->x, fractol->y, 0x000000);
	else
		my_mlx_pixel_put(img, fractol->x, fractol->y, 0xEDEDFF * (i % 255));
}

// This function will eventually be a generic function draw_fractol 
// and will be using the calculate functions to draw specific fractals
void	draw_fractal(t_data *img, t_fractol *fractol)
{
	fractol->x = 0;
	while (fractol->x <= WIN_WIDTH)
	{
		fractol->y = 0;
		while (fractol->y <= WIN_HEIGHT)
		{
			fractol->zx = 0.;
			fractol->zy = 0.;
			if (fractol->set == 'M')
				calculate_mandelbrot(img, fractol);
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_window,
		fractol->img.img_ptr, 0, 0);
}
