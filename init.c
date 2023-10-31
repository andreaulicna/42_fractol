/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:24:26 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/31 13:44:13 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	if (fractol->set == 'J')
		fractol->offset_x = -1.95;
	else
		fractol->offset_x = -2.25;
	fractol->offset_y = -1.5;
	fractol->zoom = 200;
	fractol->max_iter = 100;
	fractol->color_change = 0;
	fractol->cx = 0;
	fractol->cy = 0;
	fractol->t = 0.5;
}

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (fractol->set == 'M')
		fractol->mlx_window = mlx_new_window(fractol->mlx,
				WIN_WIDTH, WIN_HEIGHT, "Mandelbrot Fractal");
	else if (fractol->set == 'J')
		fractol->mlx_window = mlx_new_window(fractol->mlx,
				WIN_WIDTH, WIN_HEIGHT, "Julia Fractal");
	else
		fractol->mlx_window = mlx_new_window(fractol->mlx,
				WIN_WIDTH, WIN_HEIGHT, "Burning Ship Fractal");
}

void	init_img(t_fractol *fractol, t_data *img)
{
	img->img_ptr = mlx_new_image(fractol->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->size_line, &img->endian);
}
