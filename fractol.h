/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:53:07 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/26 10:52:51 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include "libftprintf/ft_printf.h"
# include <stdlib.h>
# include <float.h>
# include <stdio.h> //remove

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define MAX_ITERATIONS 300
# define ESC 27

typedef struct s_data
{
 void *img_ptr;
 void  *addr;
 int  bits_per_pixel;
 int  size_line;
 int  endian;
}             t_data;

typedef struct s_fractol
{
 char set;
 void *mlx;
 void *mlx_window;
 t_data img;
 int x;
 int y;
 double zy;
 double zx;
 double cy;
 double cx;
 double zoom;
 double offset_x;
 double offset_y;
}             t_fractol;

// input.c
void	no_invalid_parameter(void);
char	get_set(int argc, char **argv);

// draw.c
void	draw_fractal(t_data *img, t_fractol *fractol);

#endif