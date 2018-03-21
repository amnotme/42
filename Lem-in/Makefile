# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 21:17:42 by lhernand          #+#    #+#              #
#    Updated: 2018/03/13 21:57:17 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make -C
NAME = lem-in
LIB = libft/
CC = gcc
CFLAGS = -Wall -Wextra -Werror 

CFILES = $(LIB)/libft.a \
		 lem_in.c

LIBM = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean
OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@$(LIBM)
	@echo "\033[0;32mCompiling\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(CFILES)
	@echo "\033[0;33mCompiled\033[0m"

clean:
	@$(LIBC)
	@echo "\033[0;32mCleaning *.o files\033[0m"
	@/bin/rm -f $(OBJECTS)
	@echo "\033[0;33m*.o files cleaned\033[0m"

fclean:
	@$(LIBF)
	@echo "\033[0;32mCleaning *.o files and ./lem-in\033[0m"
	@/bin/rm -f $(OBJECTS) $(NAME)
	@echo "\033[0;33m*.o files and ./lem-in cleaned\033[0m"

re: fclean all 

.PHONY: all, clean, fclean, re
