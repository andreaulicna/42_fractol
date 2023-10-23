/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:39:16 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/23 16:36:11 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	no_invalid_parameter(void)
{
	ft_printf("No or invalid parameter(s) were provided :(\n");
	ft_printf("Try one of the following: \n");
	ft_printf("./fractol m || ./fractol M || ./fractol Mandelbrot\n"
		"./fractol j || ./fractol J || ./fractol Julia\n"
		"./fractol b || ./fractol B || ./fractol Burning Ship\n");
}

char	get_set(int argc, char **argv)
{
	char	*input;

	input = argv[1];
	if (argc == 2)
	{
		if (!(ft_strncmp(input, "M", 2)) || !(ft_strncmp(input, "m", 2))
			|| !(ft_strncmp(input, "Mandelbrot", 11)))
			return ('M');
		else if (!(ft_strncmp(input, "J", 2)) || !(ft_strncmp(input, "j", 2))
			|| !(ft_strncmp(input, "Julia", 6)))
			return ('J');
		else if (!(ft_strncmp(input, "B", 2)) || !(ft_strncmp(input, "b", 2))
			|| !(ft_strncmp(input, "Burning Ship", 13)))
			return ('B');
		else
			return ('X');
	}
	return ('X');
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_mandelbrot(t_data *img, void *mlx)
{
	img->img_ptr = mlx_new_image(mlx, 500, 500);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	my_mlx_pixel_put(img, 250, 250, 0x00FF0000);
}

int	fractol(char set)
{
	t_fractol	fractol;

	fractol.set = set;
	fractol.mlx = mlx_init();
	fractol.mlx_window = mlx_new_window(fractol.mlx, 500, 500, "Fractol");
	if (fractol.set == 'M')
		draw_mandelbrot(&fractol.img, fractol.mlx);
	mlx_put_image_to_window(fractol.mlx, fractol.mlx_window,
		fractol.img.img_ptr, 0, 0);
	mlx_loop(fractol.mlx);
	return (EXIT_SUCCESS);
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
