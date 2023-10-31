/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:57:46 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/31 12:48:05 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	no_invalid_parameter(void)
{
	ft_printf("\nNo or invalid parameter(s) were provided :(\n");
	ft_printf("\n***Valid arguments***\n\n");
	ft_printf("./fractol M for Mandelbrot fractal\n");
	ft_printf("./fractol J for Julia fractal\n");
	ft_printf("./fractol B for Burning Ship fractal\n");
	ft_printf("\n***Additional options***\n\n");
	ft_printf("Arrows Keys => Move the view\n");
	ft_printf("Mouse Scroll => Zoom in and out\n");
	ft_printf("W & S => Increase or decrease the # of max. iterations\n");
	ft_printf("C => Shift color range\n");
	ft_printf("J => Change constants for the Julia fractal\n");
	ft_printf("R => Reset the fractal to the initial state\n\n");
	exit(0);
}

int	get_set(int argc, char **argv, t_fractol *fractol)
{
	char	*input;

	input = argv[1];
	if (argc == 2)
	{
		if (!ft_strncmp(input, "M", 2) || !ft_strncmp(input, "J", 2)
			|| !ft_strncmp(input, "B", 2))
		{
			fractol->set = argv[1][0];
			return (0);
		}
	}	
	return (no_invalid_parameter());
}
