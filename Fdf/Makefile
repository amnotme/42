# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 23:27:35 by lhernand          #+#    #+#              #
#    Updated: 2017/12/16 17:28:27 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make -C
NAME = fdf
LIB = libft
MLX_LIB = minilibx
MLX_FRA = $(MLX_LIB)/ -L  minilibx -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror 
CC = gcc

CFILES = $(LIB)/libft.a \
		 $(MLX_LIB)/libmlx.a \
		 main.c

LIBM = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean
MLXM = $(MAKE) $(MLX_LIB) re
MLXC = $(MAKE) $(MLX_LIB) clean
OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	$(LIBM)
	$(MLXM)
	@echo "\033[32mLibft Successfully Compiled\033[0m"
	$(CC) $(CFLAGS) -o $(NAME) -I $(MLX_FRA) $(CFILES)
	@echo "\033[41m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m"
	@echo "\033[41m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m"
	@echo "\033[41m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m"
	@echo "\033[41m~~~~~~~~~~\033[47m      \033[41m~~~~~~~~~~~~~~~~~~~~\033[0m"
	@echo "\033[41m~~~~~~~~~~\033[47m  \033[41m~~~~~~~~~~~~~~~~~~~~~~~~\033[0m"
	@echo "\033[41m~~~~~~~~~~\033[47m    \033[41m~~~~~~~~~~~~~~~~~~~~~~\033[0m"
	@echo "\033[41m~~~~~~~~~~\033[47m  \033[41m~~~~~~~~~~~~~~~~~~~~~~~~\033[0m"
	@echo "\033[41m~~~~~~~~~~\033[47m  \033[41m~~\033[47m     \033[41m~~~~~~~~~~~~~~~~~\033[0m"
	@echo "\033[41m~~~~~~~~~~~~~~\033[47m  \033[41m~~\033[47m  \033[41m~~~~~~~~~~~~~~~~\033[0m"
	@echo "\033[41m~~~~~~~~~~~~~~\033[47m  \033[41m~~\033[47m   \033[41m~~~~~~~~~~~~~~~\033[0m"
	@echo "\033[41m~~~~~~~~~~~~~~\033[47m  \033[41m~~\033[47m  \033[41m~~~~~~~~~~~~~~~~\033[0m"
	@echo "\033[41m~~~~~~~~~~~~~~\033[47m     \033[41m~~~~~~~~~~~~~~~~~\033[0m"
	@echo "\033[41m~~~~~~~~~~~~~~~~~~~~\033[47m      \033[41m~~~~~~~~~~\033[0m"
	@echo "\033[41m~~~~~~~~~~~~~~~~~~~~\033[47m  \033[41m~~~~~~~~~~~~~~\033[0m"
	@echo "\033[41m~~~~~~~~~~~~~~~~~~~~\033[47m    \033[41m~~~~~~~~~~~~\033[0m"
	@echo "\033[41m~~~~~~~~~~~~~~~~~~~~\033[47m  \033[41m~~~~~~~~~~~~~~\033[0m"
	@echo "\033[41m~~~~~~~~~~~~~~~~~~~~\033[47m  \033[41m~~~~~~~~~~~~~~\033[0m"
	@echo "\033[41m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m"
	@echo "\033[41m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m"
	@echo "\033[32mfdf Successfully Compiled\033[0m"

clean:
	$(LIBC)
	@echo "\033[32m.o Files From libft/ Successfully Removed\033[0m"
	/bin/rm -f $(OBJECTS)
	@echo "\033[32m.o Files From ./ Successfully Removed\033[0m"

fclean:
	$(LIBF)
	$(MLXC)
	@echo "\033[32m.o Files From libft/ and libft.a Successfully Removed\033[0m"
	/bin/rm -f $(OBJECTS) $(NAME)
	@echo "\033[32m.o Files From libft/ and ./fdf Successfully Removed\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
