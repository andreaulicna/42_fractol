/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:22:56 by aulicna           #+#    #+#             */
/*   Updated: 2023/11/07 08:15:16 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol_bonus.h"

static void	change_constants_julia(int key, t_fractol *fractol)
{
	if (key == A)
		fractol->cy += 0.1;
	else if (key == D)
		fractol->cy -= 0.1;
	else if (key == W)
		fractol->cx += 0.1;
	else if (key == S)
		fractol->cx -= 0.1;
}

int	key_hook(int key, t_fractol *fractol)
{
	if (key == ESC)
		exit_fractol(fractol);
	else if (key == RIGHT)
		fractol->offset_x += MOVE_STEP / fractol->zoom;
	else if (key == LEFT)
		fractol->offset_x -= MOVE_STEP / fractol->zoom;
	else if (key == UP)
		fractol->offset_y -= MOVE_STEP / fractol->zoom;
	else if (key == DOWN)
		fractol->offset_y += MOVE_STEP / fractol->zoom;
	else if (key == RESET)
		init_fractol(fractol);
	else if (key == ADD_ITER && fractol->max_iter < 3000)
		fractol->max_iter += ITER_STEP;
	else if (key == RM_ITER && fractol->max_iter > 25)
		fractol->max_iter -= ITER_STEP;
	else if (key == COLOR)
		fractol->color_change += 0x78370c;
	else if ((key == W || key == S || key == A || key == D)
		&& fractol->set == 'J')
		change_constants_julia(key, fractol);
	redraw(fractol);
	return (0);
}

int	mouse_hook(int mouse_key, int x, int y, t_fractol *fractol)
{
	double	zoom_change;

	zoom_change = 1.5;
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
	redraw(fractol);
	return (0);
}
