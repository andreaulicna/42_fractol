/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:39:16 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/31 12:49:56 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_fractol(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->mlx_window);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (!get_set(argc, argv, &fractol))
	{
		init_fractol(&fractol);
		init_mlx(&fractol);
		init_img(&fractol, &fractol.img);
		draw_fractal(&fractol.img, &fractol);
		mlx_hook(fractol.mlx_window, 17, 0, exit_fractol, &fractol);
		mlx_key_hook(fractol.mlx_window, key_hook, &fractol);
		mlx_mouse_hook(fractol.mlx_window, mouse_hook, &fractol);
		mlx_loop_hook(fractol.mlx, redraw, &fractol);
		mlx_loop(fractol.mlx);
	}
	return (0);
}