/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:57:50 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/24 22:49:54 by aulicna          ###   ########.fr       */
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
	int	i;
	(void) i;

	fractol->x = 0;
	while (fractol->x <= WIN_WIDTH)
	{
		fractol->y = 0;
		while (fractol->y <= WIN_HEIGHT)
		{
			i = 0;
		//	while (i < MAX_ITERATIONS)
		//	{
		//		i++;
		//	}
			ft_printf("x: %d, y: %d\n", fractol->x, fractol->y);
			int r = (fractol->x * 255 / WIN_WIDTH) % 256;
			int g = (fractol->y * 255 / WIN_HEIGHT) % 256;
			int b = (fractol->x + fractol->y) % 256;
			int color = (r << 16) | (g << 8) | b;  // RGB color value
			my_mlx_pixel_put(img, fractol->x, fractol->y, color);
			fractol->y++;
		}
		fractol->x++;
	}
}
