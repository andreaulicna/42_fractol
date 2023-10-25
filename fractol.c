/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:39:16 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/25 14:07:12 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *fractol, char set)
{
	fractol->set = set;
	fractol->mlx = mlx_init();
	fractol->mlx_window = mlx_new_window(fractol->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	fractol->x = 0;
	fractol->y = 0;
	fractol->zx = 0.;
	fractol->zy = 0.;
	fractol->offset_x = -2.25;
	fractol->offset_y = -1.5;
	fractol->zoom = 200;
}

int	fractol(char set)
{
	t_fractol	fractol;

	init_fractol(&fractol, set);
	fractol.img.img_ptr = mlx_new_image(fractol.mlx, WIN_WIDTH, WIN_HEIGHT);
	fractol.img.addr = mlx_get_data_addr(fractol.img.img_ptr, &fractol.img.bits_per_pixel,
			&fractol.img.size_line, &fractol.img.endian);
	if (fractol.set == 'M')
		draw_mandelbrot(&fractol.img, &fractol);
	mlx_put_image_to_window(fractol.mlx, fractol.mlx_window,
		fractol.img.img_ptr, 0, 0);
	mlx_loop(fractol.mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	char	set;

	set = get_set(argc, argv);
	if (set != 'X')
		return (fractol(set));
	else
		no_invalid_parameter();
	return (EXIT_SUCCESS);
}
