/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:22:56 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/26 20:46:17 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key, t_fractol *fractol)
{
	if (key == ESC)
		exit_fractol(fractol);
	else if (key == RIGHT)
		fractol->offset_x += MOVE / fractol->zoom;
	else if (key == LEFT)
		fractol->offset_x -= MOVE / fractol->zoom;
	else if (key == UP)
		fractol->offset_y -= MOVE / fractol->zoom;
	else if (key == DOWN)
		fractol->offset_y += MOVE / fractol->zoom;
	else if (key == RESET)
		init_fractol(fractol);
	else if (key == ADD_ITER && fractol->max_iter < 3000)
		fractol->max_iter += ITER_STEP;
	else if (key == RM_ITER && fractol->max_iter > 25)
		fractol->max_iter -= ITER_STEP;
	mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
	init_img(fractol, &fractol->img);
	draw_fractal(&fractol->img, fractol);
	return (0);
}

int	mouse_hook(int mouse_key, int x, int y, t_fractol *fractol)
{
	double	zoom_change;

	zoom_change = 1.5;
	mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
	init_img(fractol, &fractol->img);
	if (mouse_key == SCRL_UP)
	{
		fractol->offset_x = (x / fractol->zoom + fractol->offset_x)
			- (x / (fractol->zoom * zoom_change));
		fractol->offset_y = (y / fractol->zoom + fractol->offset_y)
			- (y / (fractol->zoom * zoom_change));
		fractol->zoom *= zoom_change;
	}
	else if (mouse_key == SCRL_DOWN)
	{
		fractol->offset_x = (x / fractol->zoom + fractol->offset_x)
			- (x / (fractol->zoom / zoom_change));
		fractol->offset_y = (y / fractol->zoom + fractol->offset_y)
			- (y / (fractol->zoom / zoom_change));
		fractol->zoom /= zoom_change;
	}
	draw_fractal(&fractol->img, fractol);
	return (0);
}
