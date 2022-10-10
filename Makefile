# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 10:43:32 by ltrinchi          #+#    #+#              #
#    Updated: 2022/10/06 11:29:57 by lorampon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = \
				main.c \
				get_next_line.c \
				get_next_line_utils.c \
				img_to_window.c \
				exec.c \
				move.c \
				create_map.c \
				check_map.c \
				sprite.c \
				misc.c

OBJS_NAME = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_DIR),$(OBJS_NAME))

OBJ_DIR = objs/
SRC_DIR = srcs/

LIB_DIR = libft/
LIB_A = $(LIB_DIR)libft.a

MLX_DIR = mlx/
MLX_A = $(MLX_DIR)libmlx.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

FLAGS_MLX = -framework OpenGL -framework AppKit

RM = rm -rf

all: rcs $(OBJ_DIR) $(NAME)
	printf "Cest compile"

$(NAME) : $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) $(LIB_A) $(MLX_A) $(FLAGS_MLX) -o $(NAME)
	echo "##### so_long compiling finished! #####"

rcs: 
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c includes/so_long.h Makefile libft/libft.a
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make -C $(LIB_DIR) clean --silent
	$(RM) $(OBJS) $(OBJ_DIR)
	echo "##### Removed object files #####"

fclean: clean
	make -C $(LIB_DIR) fclean --silent
	$(RM) $(NAME)
	echo "##### Removed binary files #####"

re : fclean all

git: fclean
	git add *
	git add -u
	git commit
	
.PHONY: all clean fclean leaks re

.SILENT: