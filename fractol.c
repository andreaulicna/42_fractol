/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:39:16 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/24 11:55:16 by aulicna          ###   ########.fr       */
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
}


int	fractol(char set)
{
	t_fractol	fractol;

	init_fractol(&fractol, set);
	while(fractol.x <= WIN_WIDTH)
	{
		while (fractol.y <= WIN_HEIGHT)
		{
			if (fractol.set == 'M')
				draw_mandelbrot(&fractol.img, fractol.mlx);
			fractol.y++;
		}
				fractol.x++;
	}
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
