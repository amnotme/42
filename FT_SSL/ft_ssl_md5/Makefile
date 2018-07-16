# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 11:29:32 by lhernand          #+#    #+#              #
#    Updated: 2018/07/16 01:08:45 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make -C
NAME = ft_ssl
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = libft/
CFILES = $(LIB)/libft.a \
		 main.c \
		 md5_print_error.c \
		 md5_init.c \
		 md5_file_parser.c \
		 md5_update.c


#These options are here in case the lib needs to be recompiled.
#LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
LIBM = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean
OBJECTS = $(CFILES:.c=.o)


all: $(NAME)

$(NAME) : 
	@echo "\033[1;32mCompiling"
	$(LIBM)
	$(CC) $(CFLAGS) -I. -o $(NAME) $(CFILES)
	@echo "Done\033[0m"

fclean :
	@echo "\033[1;31mFull Clean"
	$(LIBF)
	/bin/rm -f $(NAME) $(OBJECTS)
	@echo "Done\033[0m"

clean :
	@echo "\033[1;33mClean"
	$(LIBF)
	/bin/rm -f $(NAME) $(OBJECTS)
	@echo "Done\033[0m"

re: fclean all

.PHONY: all, re, clean, fclean
