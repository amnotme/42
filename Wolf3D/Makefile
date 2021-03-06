# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 23:03:29 by lhernand          #+#    #+#              #
#    Updated: 2018/02/12 00:42:48 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make -C
NAME = wolf3d
TEST = test_wolf3d
LIB = libft
MLX_LIB = minilibx
MLX_FLA = $(MLX_LIB)/ -L minilibx -lmlx -framework OpenGL -framework Appkit
CFLAGS = -Wall -Wextra -Werror
CC = gcc

CFILES = $(LIB)/libft.a \
		 $(MLX_LIB)/libmlx.a \
		 main.c \
		 step_1_hooks.c \
		 step_2_setmap.c \
		 step_3_raycast.c

LIBM = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean
MLXM = $(MAKE) $(MLX_LIB) re
MLXC = $(MAKE) $(MLX_LIB) clean
OBJECTS = $(CFILES:.c=.o)

test:
	@$(CC) $(CFLAGS) -o $(TEST) -I $(MLX_FLA) $(CFILES)
	@echo "\033[32mcompiling test\033[0m"

ftest:
	@/bin/rm -f $(TEST)
	@echo "\033[32mTesting file erased\033[0m"


all: $(NAME)

$(NAME):
	@$(LIBM)
	@$(MLXM)
	@$(CC) $(CFLAGS) -o $(NAME) -I $(MLX_FLA) $(CFILES)
	@echo "\033[32mwolf3d Successfully Compiled\033[0m"

clean:
	@$(LIBC)
	@echo "\033[32m.o files from libft/ successfully removed\033[0m"
	@$(MLXC)
	@echo "\033[32m.o files from minilibx/ successfully removed\033[0m"
	@/bin/rm -f $(OBJECTS)
	@echo "\033[32m.o files from ./ successfully removed\033[0m"

fclean:
	@$(LIBF)
	@echo "\033[32m.o files from libft/ and libft.a successfully removed\033[0m"
	@/bin/rm -f $(OBJECTS) $(NAME)
	@echo "\033[32m.o files from ./ and ./wolf3d successfully removed\033[0m"

re: fclean all test ftest

.PHONY: all, clean, fclean, re
