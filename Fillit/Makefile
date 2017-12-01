# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 15:05:14 by lhernand          #+#    #+#              #
#    Updated: 2017/11/30 18:37:05 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#Make holds the make command and "-C" flag to change into the libft dir.

MAKE = make -C
NAME = fillit
LIB = libft/
CFLAGS = -Wall -Wextra -Werror
CC = gcc

#When compiling. you need to add your .a lib
CFILES = $(LIB)/libft.a \
		 step0_errors.c \
         step1_validations.c \
		 step2_board_setup.c \
		 step3_storage_and_coordinate_reset.c \
		 step4_backtracking.c \
         main.c 

#These options are here in case the lib needs to be recompiled.
#LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
LIBM = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean

all: $(NAME)

$(NAME):
	@$(LIBM)
	@$(CC) $(CFLAGS) -I. -o $(NAME) $(CFILES)

clean:
	@$(LIBC)
	@/bin/rm -f $(OBJECTS)

fclean:
	@$(LIBF)
	@/bin/rm -f $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
