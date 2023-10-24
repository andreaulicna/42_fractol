/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:57:50 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/24 14:42:44 by aulicna          ###   ########.fr       */
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
// int i;
// double x;
// double y;
// double x_tmp;

	img->img_ptr = mlx_new_image(fractol->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->size_line, &img->endian);
// i = 0;
// while (i <= MAX_ITERATIONS)
// {
//  x_tmp = x * x + y * y;
//  y = 2. * x * y;
//  x = x_tmp;
//  if (x * x + y * y == __DBL_MAX__)
//   break ;
//  i++;
// }
// if (i == MAX_ITERATIONS)
//	 my_mlx_pixel_put(img, x, y, 0x000000);
// else
//	 my_mlx_pixel_put(img, x, y, 0x00FF0000 * (i % 255));
 my_mlx_pixel_put(img, 250, 250, 0xFF0000);
}