/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:39:16 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/26 14:20:05 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_fractol(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->mlx_window);
	exit(0);
}

int	fractol(char set)
{
	t_fractol	fractol;

	init_fractol(&fractol, set);
	init_mlx(&fractol);
	init_img(&fractol, &fractol.img);
	draw_fractal(&fractol.img, &fractol);
	mlx_hook(fractol.mlx_window, 17, 0, exit_fractol, &fractol);
	mlx_key_hook(fractol.mlx_window, key_hook, &fractol);
	mlx_mouse_hook(fractol.mlx_window, mouse_hook, &fractol);
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