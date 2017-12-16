# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 23:27:35 by lhernand          #+#    #+#              #
#    Updated: 2017/12/15 23:43:34 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make -C
NAME = fdf
LIB = libft/
CFLAGS = -Wall -Wextra -Werror
CC = gcc

CFILES = $(LIB)/lift.a \
		 main.c

LIBM = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean
OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	$(LIBM)
	$(CC) $(CFLAGS) -I. -o $(NAME) $(CFILES)

clean:
	$(LIBC)
	/bin/rm -f $(OBJECTS)

fclean:
	$(LIBF)
	/bin/rm -f $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
