/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:24:26 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/26 14:19:55 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *fractol, char set)
{
	fractol->set = set;
	fractol->x = 0;
	fractol->y = 0;
	fractol->zx = 0.;
	fractol->zy = 0.;
	fractol->offset_x = -2.25;
	fractol->offset_y = -1.5;
	fractol->zoom = 200;
}

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->mlx_window = mlx_new_window(fractol->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
}

void init_img(t_fractol *fractol, t_data *img)
{
	img->img_ptr = mlx_new_image(fractol->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->size_line, &img->endian);
}