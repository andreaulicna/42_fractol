/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:53:07 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/31 13:54:54 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include "libftprintf/ft_printf.h"
# include <stdlib.h>
# include <float.h>
# include <math.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define ESC 65307
# define RIGHT 65363
# define LEFT 65361
# define UP 65362
# define DOWN 65364
# define MOVE_STEP 15
# define SCRL_UP 4
# define SCRL_DOWN 5
# define RESET 114 // R
# define ADD_ITER 119 // W
# define RM_ITER 115 // S
# define ITER_STEP 25
# define COLOR 99 // C
# define JULIA 106 // J

typedef struct s_data
{
	void	*img_ptr;
	void	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_data;

typedef struct s_fractol
{
	char	set;
	void	*mlx;
	void	*mlx_window;
	t_data	img;
	int		x;
	int		y;
	double	zy;
	double	zx;
	double	cy;
	double	cx;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		max_iter;
	int		color;
	int		color_change;
	double	t;
}	t_fractol;

// input.c
int		no_invalid_parameter(void);
int		get_set(int argc, char **argv, t_fractol *fractol);

// init.c
void	init_fractol(t_fractol *fractol);
void	init_mlx(t_fractol *fractol);
void	init_img(t_fractol *fractol, t_data *img);

// calculate.c
void	calculate_mandelbrot(t_fractol *fractol);
void	calculate_julia(t_fractol *fractol);
void	calculate_burning_ship(t_fractol *fractol);

// draw.c
void	draw_fractal(t_data *img, t_fractol *fractol);
int		redraw(t_fractol *fractol);

// hook.c
int		key_hook(int key, t_fractol *fractol);
int		mouse_hook(int mouse_key, int x, int y, t_fractol *fractol);

// fractol.c
int		exit_fractol(t_fractol *fractol);

// color.c
int		color_mandelbrot(int c);
int		color_julia(int i);

#endif