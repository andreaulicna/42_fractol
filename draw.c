/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:57:50 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/25 14:11:29 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_mandelbrot(t_data *img, t_fractol *fractol)
{
	int		i;
	double	x_tmp;

	fractol->x = 0;
	while (fractol->x <= WIN_WIDTH)
	{
		fractol->y = 0;
		while (fractol->y <= WIN_HEIGHT)
		{
			i = 0;
			fractol->zx = 0.;
			fractol->zy = 0.;
			fractol->cx = fractol->x / fractol->zoom + fractol->offset_x;
			fractol->cy = fractol->y / fractol->zoom + fractol->offset_y;
			while (fractol->zx * fractol->zx + fractol->zy * fractol->zy < __DBL_MAX__
				&& ++i < MAX_ITERATIONS)
			{
				x_tmp = fractol->zx * fractol->zx - fractol->zy * fractol->zy
					+ fractol->cx;
				fractol->zy = 2. * fractol->zx * fractol->zy + fractol->cy;
				fractol->zx = x_tmp;
			}
			if (i == MAX_ITERATIONS)
			{
			// ft_printf("max\n");
				my_mlx_pixel_put(img, fractol->x, fractol->y, 0x000000);
			}
			else
			{
			// ft_printf("not max\n");
			//	int r = (fractol->x * 255 / WIN_WIDTH) % 256;
			//	int g = (fractol->y * 255 / WIN_HEIGHT) % 256;
			//	int b = (fractol->x + fractol->y) % 256;
			//	int color = (r << 16) | (g << 8) | b;  // RGB color value
			//	my_mlx_pixel_put(img, fractol->x, fractol->y, color);
				my_mlx_pixel_put(img, fractol->x, fractol->y, 0xEDEDFF * i);
			}
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
}
