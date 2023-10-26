/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:39:16 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/26 11:49:02 by aulicna          ###   ########.fr       */
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

void	init_mlx_img(t_fractol *fractol, t_data *img)
{
	fractol->mlx = mlx_init();
	fractol->mlx_window = mlx_new_window(fractol->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	img->img_ptr = mlx_new_image(fractol->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->size_line, &img->endian);
}

int	exit_fractol(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->mlx_window);
	exit(0);
}

int	key_hook(int key, t_fractol *fractol)
{
	if (key == 65307)
	{
		printf("hej");
	 mlx_destroy_window(fractol->mlx, fractol->mlx_window);
		exit(0);
	}
	return (0);
}

int	fractol(char set)
{
	t_fractol	fractol;

	init_fractol(&fractol, set);
	init_mlx_img(&fractol, &fractol.img);
	draw_fractal(&fractol.img, &fractol);
	mlx_put_image_to_window(fractol.mlx, fractol.mlx_window,
		fractol.img.img_ptr, 0, 0);
	mlx_hook(fractol.mlx_window, 17, 0, exit_fractol, &fractol);
	mlx_key_hook(fractol.mlx_window, key_hook, &fractol);
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
