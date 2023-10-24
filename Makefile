# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 13:48:36 by aulicna           #+#    #+#              #
#    Updated: 2023/10/24 09:52:05 by aulicna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = fractol.c \
						input.c \
						draw.c
OBJ = $(SRC:.c=.o)

LIBFTPRINTF = libftprintf
LIBFT = libftprintf/libft
MLX = minilibx

CFLAGS = -Wall -Werror -Wextra

GCC = gcc

all: libs $(NAME)

libs:
	@make -C $(LIBFTPRINTF)
	@echo "libprintf library ready ✅"
	@make -C $(MLX)
	@echo "minilibx library ready ✅"
	
$(NAME): $(OBJ)
		$(GCC) $(CFLAGS) -L $(LIBFT) -L $(LIBFTPRINTF) -L $(MLX) -o $@ $^ -lft -lftprintf -lmlx -lXext -lX11 -lm

clean:
	@make clean -C $(LIBFTPRINTF)
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@make fclean -C $(LIBFTPRINTF)
	
re:	fclean
	@make all
	
.PHONY: all clean fclean re

