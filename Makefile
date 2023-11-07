# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 13:48:36 by aulicna           #+#    #+#              #
#    Updated: 2023/11/07 08:15:26 by aulicna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_B = fractol_bonus

SRC = src/main.c \
						src/input.c \
						src/init.c \
						src/calculate.c \
						src/draw.c \
						src/hook.c \
						src/color.c
SRC_B = src_bonus/main_bonus.c \
						src_bonus/input_bonus.c \
						src_bonus/init_bonus.c \
						src_bonus/calculate_bonus.c \
						src_bonus/draw_bonus.c \
						src_bonus/hook_bonus.c \
						src_bonus/color_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

HEADER = incl/fractol.h
HEADER_B = incl/fractol_bonus.h

LIBFTPRINTF = libftprintf
LIBFT = libftprintf/libft
MLX = minilibx

CFLAGS = -Wall -Werror -Wextra

GCC = gcc

all: libs $(NAME)
	@echo "fractol executable ready ✅"

bonus: libs $(NAME_B)
	@echo "fractol_bonus executable ready ✅"

.c.o:
	$(GCC) $(CFLAGS) -c $< -o $@

libs:
	@make -C $(LIBFTPRINTF)
	@echo "libprintf library ready ✅"
	@make -C $(MLX)
	@echo "minilibx library ready ✅"
	
$(NAME): $(OBJ) $(HEADER)
		$(GCC) $(CFLAGS) -L $(LIBFT) -L $(LIBFTPRINTF) -L $(MLX) -o $@ $^ -lft -lftprintf -lmlx -lXext -lX11 -lm

$(NAME_B): $(OBJ_B) $(HEADER_B)
		$(GCC) $(CFLAGS) -L $(LIBFT) -L $(LIBFTPRINTF) -L $(MLX) -o $@ $^ -lft -lftprintf -lmlx -lXext -lX11 -lm

clean:
	@make clean -C $(LIBFTPRINTF)
	@rm -f $(OBJ)
	@rm -f $(OBJ_B)

fclean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_B)
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	@make fclean -C $(LIBFTPRINTF)
	
re: fclean all

re_bonus: fclean bonus
	
.PHONY: all clean fclean re