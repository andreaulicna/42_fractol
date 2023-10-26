/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:53:07 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/26 12:44:27 by aulicna          ###   ########.fr       */
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
# define ESC 65307
# define RIGHT 65363
# define LEFT 65361
# define UP 65362
# define DOWN 65364
# define MOVE 15

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

// init.c
void	init_fractol(t_fractol *fractol, char set);
void	init_mlx_img(t_fractol *fractol, t_data *img);

// draw.c
void	draw_fractal(t_data *img, t_fractol *fractol);

// hook.c
int	key_hook(int key, t_fractol *fractol);

// fractol.c
int	exit_fractol(t_fractol *fractol);

#endif