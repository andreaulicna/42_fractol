/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:57:50 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/31 16:07:51 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_fractal(t_data *img, t_fractol *fractol)
{
	fractol->x = 0;
	while (fractol->x <= WIN_WIDTH)
	{
		fractol->y = 0;
		while (fractol->y <= WIN_HEIGHT)
		{
			if (fractol->set == 'M')
				calculate_mandelbrot(fractol);
			else if (fractol->set == 'B')
				calculate_burning_ship(fractol);
			else if (fractol->set == 'J')
				calculate_julia(fractol);
			my_mlx_pixel_put(img, fractol->x, fractol->y, fractol->color);
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_window,
		fractol->img.img_ptr, 0, 0);
}

int	redraw(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
	init_img(fractol, &fractol->img);
	draw_fractal(&fractol->img, fractol);
	return (0);
}
