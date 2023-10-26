/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:22:56 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/26 12:44:25 by aulicna          ###   ########.fr       */
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
 draw_fractal(&fractol->img, fractol);
	return (0);
}