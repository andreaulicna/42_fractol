/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:57:46 by aulicna           #+#    #+#             */
/*   Updated: 2023/11/07 05:47:53 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	no_invalid_argument(void)
{
	ft_printf("\nNo or invalid parameter(s) were provided :(\n");
	ft_printf("\n***Valid arguments***\n\n");
	ft_printf("./fractol M for Mandelbrot fractal\n");
	ft_printf("./fractol J1, J2, J3 for Julia fractal\n");
	ft_printf("./fractol B for Burning Ship fractal\n");
	ft_printf("\n***Additional options***\n\n");
	ft_printf("Arrows keys => Move the view\n");
	ft_printf("Mouse scroll => Zoom in and out\n");
	ft_printf("I & K keys => Increase or decrease the # of max. iterations\n");
	ft_printf("C key => Shift color range\n");
	ft_printf("W, S, A & D keys => Change constants for the Julia fractal\n");
	ft_printf("R key => Reset the fractal to the initial state\n\n");
	exit(0);
}

int	get_set(int argc, char **argv, t_fractol *fractol)
{
	char	*input;

	input = argv[1];
	if (argc == 2)
	{
		if (!ft_strncmp(input, "M", 2) || !ft_strncmp(input, "B", 2))
		{
			fractol->set = argv[1][0];
			return (0);
		}
		else if (!ft_strncmp(input, "J1", 3) || !ft_strncmp(input, "J2", 3)
			|| !ft_strncmp(input, "J3", 3))
		{
			fractol->set = argv[1][0];
			fractol->julia_num = argv[1][1];
			return (0);
		}
	}	
	return (no_invalid_argument());
}
