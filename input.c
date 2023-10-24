/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:57:46 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/24 09:42:55 by aulicna          ###   ########.fr       */
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