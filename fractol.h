/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:53:07 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/24 11:37:17 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include "libftprintf/ft_printf.h"
# include <stdlib.h>
# include <float.h>

# define WIN_WIDTH 1080
# define WIN_HEIGHT 500
# define MAX_ITERATIONS 500

typedef struct s_data
{
 void *img_ptr;
 void *addr;
 int bits_per_pixel;
 int size_line;
 int endian;
}             t_data;

typedef struct s_fractol
{
 char set;
 void *mlx;
 void *mlx_window;
 t_data img;
 int x;
 int y;
}             t_fractol;

// input.c
void	no_invalid_parameter(void);
char	get_set(int argc, char **argv);

// draw.c
void	draw_mandelbrot(t_data *img, void *mlx);


#endif