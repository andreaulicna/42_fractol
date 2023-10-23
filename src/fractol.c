/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:39:16 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/23 12:34:51 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	no_invalid_parameter(void)
{
	ft_printf("No or invalid parameter(s) were provided :(\n");
	ft_printf("Try the following: \n");
}


int	fractol(char *set)
{
	(void) set;
	t_fractol	*fractol;

	fractol = malloc(sizeof(t_fractol));
	fractol->mlx = mlx_init(50, 50, "Fractol", true);
	ft_printf("jo");
	if (!fractol->mlx)
		return (write(2, "Error\n", 6));
	mlx_loop(fractol->mlx);
	return (EXIT_SUCCESS);
}


int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!(ft_strncmp(argv[1], "Mandelbrot", 11)) || !(ft_strncmp(argv[1], "M", 2))
			|| !(ft_strncmp(argv[1], "m", 2)))
		{	
			return (fractol(argv[1]));
		}
		else
			no_invalid_parameter();
	}
	else
		no_invalid_parameter();
	return (EXIT_SUCCESS);
}