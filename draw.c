/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:57:50 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/27 17:01:46 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	set_z_c(t_fractol *fractol)
{
	if (fractol->set == 'M' || fractol->set == 'B')
	{
		fractol->zx = 0.;
		fractol->zy = 0.;
		fractol->cx = fractol->x / fractol->zoom + fractol->offset_x;
		fractol->cy = fractol->y / fractol->zoom + fractol->offset_y;
	}
	else if (fractol->set == 'J')
	{
		fractol->zx = fractol->x / fractol->zoom + fractol->offset_x;
		fractol->zy = fractol->y / fractol->zoom + fractol->offset_y;
		if (fractol->cx == 0 && fractol->cy == 0)
		{
			fractol->cx = -0.745429;
			fractol->cy = 0.05;
		}
	}
}

void	calculate_mandelbrot(t_data *img, t_fractol *fractol)
{
	int		i;
	int	c;
	double	x_tmp;

	i = 0;
	set_z_c(fractol);
	while (fractol->zx * fractol->zx + fractol->zy * fractol->zy < 4.
		&& i < fractol->max_iter)
	{
		x_tmp = fractol->zx * fractol->zx - fractol->zy * fractol->zy
			+ fractol->cx;
		fractol->zy = 2. * fractol->zx * fractol->zy + fractol->cy;
		fractol->zx = x_tmp;
		i++;
	}
	if (i == fractol->max_iter)
		fractol->color = 0x000000;
	else
	{
		c = i % 16;
		fractol->color = choose_color_mandelbrot(c) + fractol->color_change;
	}
	my_mlx_pixel_put(img, fractol->x, fractol->y, fractol->color);
}

void	calculate_burning_ship(t_data *img, t_fractol *fractol)
{
	int		i;
	double	x_tmp;

	i = 0;
	set_z_c(fractol);
	while (fractol->zx * fractol->zx + fractol->zy * fractol->zy < 4.
		&& i < fractol->max_iter)
	{
		x_tmp = fractol->zx * fractol->zx - fractol->zy * fractol->zy
			+ fractol->cx;
		fractol->zy = fabs(2. * fractol->zx * fractol->zy) + fractol->cy;
		fractol->zx = fabs(x_tmp);
		i++;
	}
	if (i == fractol->max_iter)
		fractol->color = 0x000000;
	else
		fractol->color = 0x6e820f * i / 100 + fractol->color_change;
	my_mlx_pixel_put(img, fractol->x, fractol->y, fractol->color);
}

void	calculate_julia(t_data *img, t_fractol *fractol)
{
	int	i;
	int	c;
	double x_tmp;

	i = 0;
	set_z_c(fractol);
	while (fractol->zx * fractol->zx + fractol->zy * fractol->zy < 4. 
		&& i < fractol->max_iter)
	{
		x_tmp = fractol->zx;
		fractol->zx = fractol->zx * fractol->zx - fractol->zy * fractol->zy
			+ fractol->cx;
		fractol->zy = 2 * fractol->zy * x_tmp + fractol->cy;
		i++;
	}
	if (i == fractol->max_iter)
		fractol->color = 0x000000;
	else
	{
		c = i % 16;
		//fractol->color = 0x7f0f50 * (i % 100) + fractol->color_change;
		fractol->color = choose_color_mandelbrot(c) + fractol->color_change;
	}
	my_mlx_pixel_put(img, fractol->x, fractol->y, fractol->color);
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
				calculate_mandelbrot(img, fractol);
			else if (fractol->set == 'B')
				calculate_burning_ship(img, fractol);
			else if (fractol->set == 'J')
				calculate_julia(img, fractol);
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_window,
		fractol->img.img_ptr, 0, 0);
}
