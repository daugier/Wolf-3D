# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daugier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 17:54:33 by daugier           #+#    #+#              #
#    Updated: 2016/10/25 23:16:23 by daugier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

RM	= rm -f

LIB = -L ./libs/libft/ -lft -L ./libs/minilibx_macos/ -lft

HEADER = -I ./include

CC = @gcc -I./include -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit 

SRCS = 	srcs/main.c \
		srcs/init_data.c \
		srcs/wolf.c \
		srcs/event.c \
		srcs/ray_cast.c \
		srcs/moove.c \
		srcs/texture.c \
		srcs/floor_raycast.c \
		srcs/info.c \
		srcs/moove_two.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@make -C libs/libft/
	@echo "\033[34m[OK]\033[36m LIBFT COMPILED"
	@make -C libs/minilibx_macos/
	@echo "\033[34m[OK]\033[36m MINILIBIX_MACOS COMPILED"
	@$(CC) $(MLX) -o $(NAME) $(OBJS) $(LIB) $(HEADER)
	@echo "\033[34m[OK]\033[36m WOLF3D COMPILED"
	@echo "\033[32m[OK]\033[32m WOLF3D CREATED, LET'S HAVE FUN GUYS !"

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@make clean -C libs/libft/
	@make clean -C libs/minilibx_macos/
	@echo "\033[31m[OK]\033[31m WOLF3D FILES O DELETED"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libs/libft/
	@make fclean -C libs/minilibx_macos/
	@echo "\033[31m[OK]\033[31m WOLF3D DELETED"

re: fclean all
